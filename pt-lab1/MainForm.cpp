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

		frequencies->clear();
		// обновление частот с учетом нового эксперимента
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
	maxError_textBox->Text = "";
	count = 0;
	rows = 0;
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

	// пересоздаем условия эксперимента для построения теор. ф-ии распределения
	experiment->SetAmountOfLightbulbs(System::Convert::ToInt32(N_textBox->Text));
	experiment->SetAmountOfSelected(System::Convert::ToInt32(R_textBox->Text));
	experiment->SetAmountOfDamaged(System::Convert::ToInt32(M_textBox->Text));

	double sum = 0.0;

	// теоретическая функция распределения
	int res_min = experiment->GetMinResult();
	int res_max = experiment->GetMaxResult();
	chart->ChartAreas[0]->AxisX->Maximum = res_max + 1;
	chart->Series[0]->Points->AddXY(0, 0);
	for (int x = res_min; x <= res_max; x++)
	{
		sum += experiment->GetProbability(x);
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
}
