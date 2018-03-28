#pragma once
#include <vector>
#include <algorithm>
#include "Experiment.h"

namespace ptlab1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{		
	private: System::Windows::Forms::DataGridView^  dataGridView;		
	private: System::Windows::Forms::TextBox^  R_textBox;
	private: System::Windows::Forms::Label^  R_label;			 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column3;
	private: System::Windows::Forms::Button^  delete_button;		 
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Label^  label;

			 Experiment* experiment;			 
			 std::vector<int> *results;
			 std::vector<double> *frequencies;

			 int rows;		// число строк в таблице			 
			 int count;		// число проведенных экспериментов
	public:
		MainForm(void)
		{
			experiment = new Experiment();
			results = new std::vector<int>;
			frequencies = new std::vector<double>;
			count = 0; rows = 0;

			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  mainButton;
	protected:

	private: System::Windows::Forms::TextBox^  N_textBox;
	private: System::Windows::Forms::TextBox^  M_textBox;
	private: System::Windows::Forms::Label^  N_label;
	private: System::Windows::Forms::Label^  M_label;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->mainButton = (gcnew System::Windows::Forms::Button());
			this->N_textBox = (gcnew System::Windows::Forms::TextBox());
			this->M_textBox = (gcnew System::Windows::Forms::TextBox());
			this->N_label = (gcnew System::Windows::Forms::Label());
			this->M_label = (gcnew System::Windows::Forms::Label());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->R_textBox = (gcnew System::Windows::Forms::TextBox());
			this->R_label = (gcnew System::Windows::Forms::Label());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// mainButton
			// 
			this->mainButton->Location = System::Drawing::Point(42, 156);
			this->mainButton->Name = L"mainButton";
			this->mainButton->Size = System::Drawing::Size(198, 52);
			this->mainButton->TabIndex = 0;
			this->mainButton->Text = L"Получить результат эксперимента (число перегоревших лампочек из числа выбранных)";
			this->mainButton->UseVisualStyleBackColor = true;
			this->mainButton->Click += gcnew System::EventHandler(this, &MainForm::mainButton_Click);
			// 
			// N_textBox
			// 
			this->N_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->N_textBox->Location = System::Drawing::Point(42, 31);
			this->N_textBox->Name = L"N_textBox";
			this->N_textBox->Size = System::Drawing::Size(87, 20);
			this->N_textBox->TabIndex = 2;
			this->N_textBox->Text = L"10";
			// 
			// M_textBox
			// 
			this->M_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M_textBox->Location = System::Drawing::Point(42, 58);
			this->M_textBox->Name = L"M_textBox";
			this->M_textBox->Size = System::Drawing::Size(87, 20);
			this->M_textBox->TabIndex = 3;
			this->M_textBox->Text = L"5";
			// 
			// N_label
			// 
			this->N_label->AutoSize = true;
			this->N_label->Location = System::Drawing::Point(147, 33);
			this->N_label->Name = L"N_label";
			this->N_label->Size = System::Drawing::Size(91, 13);
			this->N_label->TabIndex = 5;
			this->N_label->Text = L"Число лампочек";
			// 
			// M_label
			// 
			this->M_label->AutoSize = true;
			this->M_label->Location = System::Drawing::Point(147, 60);
			this->M_label->Name = L"M_label";
			this->M_label->Size = System::Drawing::Size(114, 13);
			this->M_label->TabIndex = 6;
			this->M_label->Text = L"Число перегоревших";
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->column1,
					this->column2, this->column3
			});
			this->dataGridView->Location = System::Drawing::Point(42, 214);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			dataGridViewCellStyle4->NullValue = nullptr;
			this->dataGridView->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView->Size = System::Drawing::Size(198, 206);
			this->dataGridView->TabIndex = 7;
			// 
			// column1
			// 
			this->column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->column1->HeaderText = L"y_i";
			this->column1->Name = L"column1";
			this->column1->ReadOnly = true;
			this->column1->Width = 45;
			// 
			// column2
			// 
			this->column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->column2->HeaderText = L"n_i";
			this->column2->Name = L"column2";
			this->column2->ReadOnly = true;
			this->column2->Width = 46;
			// 
			// column3
			// 
			this->column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			dataGridViewCellStyle3->Format = L"N4";
			dataGridViewCellStyle3->NullValue = nullptr;
			this->column3->DefaultCellStyle = dataGridViewCellStyle3;
			this->column3->HeaderText = L"n_i / n";
			this->column3->Name = L"column3";
			this->column3->ReadOnly = true;
			this->column3->Width = 63;
			// 
			// R_textBox
			// 
			this->R_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->R_textBox->Location = System::Drawing::Point(42, 85);
			this->R_textBox->Name = L"R_textBox";
			this->R_textBox->Size = System::Drawing::Size(87, 20);
			this->R_textBox->TabIndex = 8;
			this->R_textBox->Text = L"5";
			// 
			// R_label
			// 
			this->R_label->AutoSize = true;
			this->R_label->Location = System::Drawing::Point(147, 87);
			this->R_label->Name = L"R_label";
			this->R_label->Size = System::Drawing::Size(99, 13);
			this->R_label->TabIndex = 9;
			this->R_label->Text = L"Число выбранных";
			// 
			// delete_button
			// 
			this->delete_button->Location = System::Drawing::Point(42, 426);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(198, 31);
			this->delete_button->TabIndex = 10;
			this->delete_button->Text = L"Очистить";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &MainForm::delete_button_Click);
			// 
			// textBox
			// 
			this->textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox->Location = System::Drawing::Point(42, 112);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(87, 20);
			this->textBox->TabIndex = 11;
			this->textBox->Text = L"100";
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(147, 114);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(121, 13);
			this->label->TabIndex = 12;
			this->label->Text = L"Число экспериментов";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 495);
			this->Controls->Add(this->label);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->delete_button);
			this->Controls->Add(this->R_label);
			this->Controls->Add(this->R_textBox);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->M_label);
			this->Controls->Add(this->N_label);
			this->Controls->Add(this->M_textBox);
			this->Controls->Add(this->N_textBox);
			this->Controls->Add(this->mainButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainForm";
			this->Text = L"Лаб. работа: моделирование случайной величины";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mainButton_Click(System::Object^  sender, System::EventArgs^  e) {
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
				dataGridView->Sort(column1, System::ComponentModel::ListSortDirection::Ascending);
				rows++;
			}

			// обновление частот с учетом нового эксперимента
			for (i = 0; i < rows; i++)
			{
				frequencies->clear();
				n = System::Convert::ToDouble(dataGridView->Rows[i]->Cells[1]->Value);
				dataGridView->Rows[i]->Cells[2]->Value = n / count;

				// также добавляем в массив частот
				frequencies->push_back(System::Convert::ToDouble(dataGridView->Rows[i]->Cells[2]->Value));
			}
		}
	}

	private: System::Void delete_button_Click(System::Object^  sender, System::EventArgs^  e) {	
		dataGridView->Rows->Clear();
		frequencies->clear();
		results->clear();		
		count = 0;
		rows = 0;
	}
};
}
