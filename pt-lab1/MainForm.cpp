#include "MainForm.h"

using namespace ptlab1;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ptlab1::MainForm form;   
	Application::Run(%form);
}

System::Void ptlab1::MainForm::mainButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	double n;
	bool flag = false;
    totalExperiments += System::Convert::ToInt32(textBox->Text);
	int nExperiments = System::Convert::ToInt32(textBox->Text);
	int i = 0;
	int result;

	for (int j = 0; j < nExperiments; j++)
	{
		experiment->SetAmountOfLightbulbs(System::Convert::ToInt32(N_textBox->Text));
		experiment->SetAmountOfSelected(System::Convert::ToInt32(R_textBox->Text));
		experiment->SetAmountOfDamaged(System::Convert::ToInt32(M_textBox->Text));

		n = 0;
		flag = false;
		result = experiment->RunExperiment();
		expandedResults->push_back(result); // запоминаем результат
		count++;

		// ищем результат в таблице
		for (i = 0; i < rows; i++)
		{
			if (result == System::Convert::ToInt32(dataGridView->Rows[i]->Cells[0]->Value)) {
				n = System::Convert::ToInt32(dataGridView->Rows[i]->Cells[1]->Value) + 1;
				dataGridView->Rows[i]->Cells[1]->Value = n;
				flag = true;
				break;
			}
		}

		// если не нашли, то добавляем в таблицу
		if (flag == false) {
			results->push_back(result); // также добавляем в массив результатов 
			std::sort(results->begin(), results->end()); // и сортируем 
			dataGridView->Rows->Add();
			dataGridView->Rows[rows]->Cells[0]->Value = result;
			dataGridView->Rows[rows]->Cells[1]->Value = 1;

			// пересоздаем условия эксперимента, чтобы посчитать теоретическую вероятность
			experiment->SetAmountOfLightbulbs(System::Convert::ToInt32(N_textBox->Text));
			experiment->SetAmountOfSelected(System::Convert::ToInt32(R_textBox->Text));
			experiment->SetAmountOfDamaged(System::Convert::ToInt32(M_textBox->Text));
			dataGridView->Rows[rows]->Cells[3]->Value = experiment->GetProbability(result);

			// сортировка таблицы по возрастанию
			dataGridView->Sort(column1, System::ComponentModel::ListSortDirection::Ascending);
			rows++;
		}

        // обновление частот с учетом нового эксперимента
		frequencies->clear();		

		for (i = 0; i < rows; i++)
		{
			n = System::Convert::ToDouble(dataGridView->Rows[i]->Cells[1]->Value);
			dataGridView->Rows[i]->Cells[2]->Value = n / count;

			// также добавляем в массив частот
			frequencies->push_back(System::Convert::ToDouble(dataGridView->Rows[i]->Cells[2]->Value));
		}
	}

	dataGridView->ClearSelection();

	// сортируем все полученные значения (для вычисления медианы и размаха выборки)
	std::sort(expandedResults->begin(), expandedResults->end());

	// также требуется рассчитать характеристики
	CalculateCharacteristics();
	DrawGraphics(); // и построить графики функций распределения
}

System::Void ptlab1::MainForm::delete_button_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	dataGridView->Rows->Clear();
	dataGridView_table->Rows->Clear();
	chart->Series[0]->Points->Clear();
	chart->Series[1]->Points->Clear();
	frequencies->clear();
	results->clear();
	expandedResults->clear();
	chart->Legends[0]->Enabled = false;
	maxError_textBox->Text = "";
	divergency_textBox->Text = "";
	count = 0;
	rows = 0;
    totalExperiments = 0;
    textBox_R0->Text = "";
    label_hypothesis->Text = "";
}

double ptlab1::MainForm::GetExpectedValue()
{
	double sum = 0.0;

	for (int i = 0; i < results->size(); i++)
		sum += results->at(i) * frequencies->at(i);

	return sum;
}

double ptlab1::MainForm::GetDispersion()
{
	double EV = GetExpectedValue();
	double sum = 0.0;

	for (int i = 0; i < results->size(); i++)
		sum += pow((results->at(i) - EV), 2) * frequencies->at(i);

	return sum;
}

double ptlab1::MainForm::GetMedian()
{
	double median = 0.0;
	int size = (int)expandedResults->size();

	if (size == 1) median = expandedResults->at(size - 1);
	else
	{
		if (size % 2 == 0)
			median = (double)(expandedResults->at(size / 2 - 1) + expandedResults->at(size / 2)) / 2;
		else
			median = expandedResults->at(size / 2);
	}

	return median;
}

double ptlab1::MainForm::GetMaxError()
{
	double maxError = 0.0;
	double diff = 0.0;
	double a = 0.0;
	double b = 0.0;

	for (int i = 0; i < rows; i++) {
		a = System::Convert::ToDouble(dataGridView->Rows[i]->Cells[2]->Value);
		b = System::Convert::ToDouble(dataGridView->Rows[i]->Cells[3]->Value);
		diff = fabs(a - b);
		if (maxError < diff) maxError = diff;
	}

	return maxError;
}

void ptlab1::MainForm::CalculateCharacteristics()
{
	// пересоздаем условия эксперимента
	experiment->SetAmountOfLightbulbs(System::Convert::ToInt32(N_textBox->Text));
	experiment->SetAmountOfSelected(System::Convert::ToInt32(R_textBox->Text));
	experiment->SetAmountOfDamaged(System::Convert::ToInt32(M_textBox->Text));

	double theoryEV = experiment->GetExpectedValue();
	double realEV = GetExpectedValue();
	double theoryD = experiment->GetDispersion();
	double realD = GetDispersion();
	double median = GetMedian();
	int range = expandedResults->back() - expandedResults->front();
	double maxError = GetMaxError();

	dataGridView_table->Rows->Clear();
	dataGridView_table->Rows[0]->Cells[0]->Value = theoryEV; // теоретическое мат. ожидание
	dataGridView_table->Rows[0]->Cells[1]->Value = realEV;	 // выборочное мат. ожидание
	dataGridView_table->Rows[0]->Cells[2]->Value = fabs(theoryEV - realEV);	// отклонение мат. ожидания от теоретического
	dataGridView_table->Rows[0]->Cells[3]->Value = theoryD;  // теоретическая дисперсия
	dataGridView_table->Rows[0]->Cells[4]->Value = realD;    // выборочная дисперсия
	dataGridView_table->Rows[0]->Cells[5]->Value = fabs(theoryD - realD);   // отклонение дисперсии
	dataGridView_table->Rows[0]->Cells[6]->Value = median;   // выборочная медиана
	dataGridView_table->Rows[0]->Cells[7]->Value = range;	 // размах выборки
	dataGridView_table->ClearSelection();

	maxError_textBox->Text = System::Convert::ToString(maxError); // максимальное отклонение частоты от вероятности
}

void ptlab1::MainForm::DrawGraphics()
{	
	chart->Series[0]->Points->Clear();
	chart->Series[1]->Points->Clear();
	chart->Legends[0]->Enabled = true;

	// пересоздаем условия эксперимента для построения теор. ф-ии распределения
	experiment->SetAmountOfLightbulbs(System::Convert::ToInt32(N_textBox->Text));
	experiment->SetAmountOfSelected(System::Convert::ToInt32(R_textBox->Text));
	experiment->SetAmountOfDamaged(System::Convert::ToInt32(M_textBox->Text));

	double sum = 0.0;
	
	// теоретическая функция распределения
	int res_min = experiment->GetMinResult();
	int res_max = experiment->GetMaxResult();
	array<double>^ div = gcnew array<double>(res_max + 1); // массив для хранения значений функции распределения
	chart->ChartAreas[0]->AxisX->Maximum = res_max + 1;
	chart->Series[0]->Points->AddXY(0, 0);
	for (int x = res_min; x <= res_max; x++)
	{
		sum += experiment->GetProbability(x);
		div[x] = sum;
		chart->Series[0]->Points->AddXY(x, sum);
	}
	chart->Series[0]->Points->AddXY(res_max + 1, 1);
	
	// выборочная функция распределения 
	sum = 0.0;
	chart->Series[1]->Points->AddXY(0, 0);
	for (int i = 0; i < results->size(); i++)
	{
		sum += frequencies->at(i);
		chart->Series[1]->Points->AddXY(results->at(i), sum);	
	}
	chart->Series[1]->Points->AddXY(res_max + 1, 1);

	// вычисление меры расхождения
	int x = 0;
	double divergence = 0.0;
	double d1 = 0.0;
	double d2 = 0.0;
	double d_max = 0.0;
	double  f = 0.0;
	for (int j = 1; j <= expandedResults->size(); j++)
	{
		x = expandedResults->at(j - 1);
		f = div[x];
		d1 = ((double)j / count) - f;
		d2 = f - experiment->GetProbability(x) - ((double)(j-1)/count);
		d_max = std::max(d1, d2);
		if (divergence < d_max) divergence = d_max;
	}
	
	divergency_textBox->Text = System::Convert::ToString(divergence);
}

System::Void ptlab1::MainForm::button_save_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    k = System::Convert::ToInt32(textBox_intervals->Text);

    z->clear();
    z->resize(k + 1, 0.0);
    z->at(0) = std::numeric_limits<double>::lowest();
    z->at(k) = std::numeric_limits<double>::max();

    if (radioButton1->Checked) // автоматический выбор интервалов
    {
        z->at(1) = results->at(0) + 0.5;
        z->at(k - 1) = results->back() - 0.5;

        double interval = (z->at(k - 1) - z->at(1)) / (double)(k-2);

        for (int i = 2; i < k - 1; i++)
        {
            z->at(i) = z->at(i - 1) + interval;
        }
    }

    // ручной выбор границ интервалов
    if (radioButton2->Checked) 
    {
        for (int i = 1; i <= k-1; i++)
        {
            // считываем значения с таблицы
            z->at(i) = System::Convert::ToDouble(dataGridView_intervals->Rows[i]->Cells[1]->Value);
        }
    }

    dataGridView_intervals->Rows->Clear();
    for (int i = 0; i <= k; i++)
    {       
        dataGridView_intervals->Rows->Add();
        dataGridView_intervals->Rows[i]->Cells[0]->Value = i;
        if (i == 0) dataGridView_intervals->Rows[i]->Cells[1]->Value = - std::numeric_limits<double>::infinity();
        else if (i == k) dataGridView_intervals->Rows[i]->Cells[1]->Value = std::numeric_limits<double>::infinity();
        else dataGridView_intervals->Rows[i]->Cells[1]->Value = z->at(i);
    }
    dataGridView_intervals->ClearSelection();
}

System::Void ptlab1::MainForm::button_distribution_Click(System::Object ^ sender, System::EventArgs ^ e)
{   
    std::vector<int> exp_results = experiment->GetResults();
    std::vector<double> exp_probabilities = experiment->GetProbabilities();
    std::vector<int> n;  // n[j] - число наблюдений, попавших в интервал [z[j], z[j+1]]
    double r = 0.0;      // статистика критерия
    double eps = 1.0e-6;
    alpha = System::Convert::ToDouble(textBox_alpha->Text); // критерий значимости

    q->clear();
    q->resize(k + 1, 0.0);

    n.clear();
    n.resize(k + 1, 0);

    // вычисление теоретических вероятностей
    for (int i = 0; i < exp_results.size(); i++)
    {
        for (int j = 0; j < z->size() - 1; j++)
        {
            //  если теоретическое значение попадает в интервал [z[j], z[j+1]]
            if (((double)exp_results[i] > z->at(j)) && ((double)exp_results[i] < z->at(j + 1)))
                q->at(j + 1) += exp_probabilities[i]; // q[j] - сумма теоретических вероятностей, значений попавших в интервал           
        }
    }

    // вычисление n[j] - числа значений попавших в интервал [z[j], z[j+1]]
    // expandedResults - все получившиеся наблюдения (с повторами)
    for (int i = 0; i < expandedResults->size(); i++)
    {
        for (int j = 0; j < z->size() - 1; j++)
        {
            //  если значение эксперимента попадает в интервал [z[j], z[j+1]]
            if (((double)expandedResults->at(i) > z->at(j)) && ((double)expandedResults->at(i) < z->at(j + 1)))
                n[j+1]++; // увеличиваем счетчик числа наблюдений, попавших в интервал           
        }
    }

    // добавляем полученные значения в таблицу
    for (int j = 1; j <= k; j++)
    {
        dataGridView_intervals->Rows[j]->Cells[2]->Value = n[j];
        dataGridView_intervals->Rows[j]->Cells[3]->Value = q->at(j);
    }

    // вычисление статистики критерия ( R0 )
    for (int j = 1; j <= k; j++)
    {
        // проверка на ноль
        if (!(q->at(j) < eps && q->at(j) > -eps))
            r += (pow(((double)n[j] - (double)totalExperiments * q->at(j)), 2.0) / ((double)totalExperiments * q->at(j)));
    }

    textBox_R0->Text = System::Convert::ToString(r);

    double res = F(r, k - 1);
    textBox_F->Text = System::Convert::ToString(res);

    if (res > alpha)
        label_hypothesis->Text =  "Гипотеза принята";
    else
        label_hypothesis->Text = "Гипотеза отклонена";
}
