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
	protected:
		Experiment* experiment;
		std::vector<int> *results;		   // все полученные значения СВ
		std::vector<int> *expandedResults; // все полученные значения СВ (с повторами)
		std::vector<double> *frequencies;  // частоты полученных значений СВ
		int rows;		// число строк в таблице
		int count;		// число проведенных экспериментов

	private: System::Windows::Forms::DataGridView^  dataGridView;		
	private: System::Windows::Forms::TextBox^  R_textBox;
	private: System::Windows::Forms::Label^  R_label;			 
	private: System::Windows::Forms::Button^  delete_button;		 
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Label^  label;			 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;			 
	private: System::Windows::Forms::DataGridView^  dataGridView_table;
	private: System::Windows::Forms::Label^  table_label;
	private: System::Windows::Forms::Label^  maxError_label;
	private: System::Windows::Forms::TextBox^  maxError_textBox;
	private: System::Windows::Forms::Button^  mainButton;
	private: System::Windows::Forms::TextBox^  N_textBox;
	private: System::Windows::Forms::TextBox^  M_textBox;
	private: System::Windows::Forms::Label^  N_label;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_8;
	private: System::Windows::Forms::Label^  M_label;

	public:
		MainForm(void)
		{
			experiment = new Experiment();
			results = new std::vector<int>;
			expandedResults = new std::vector<int>;
			frequencies = new std::vector<double>;		
			count = 0; 
			rows = 0;

			InitializeComponent();
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle58 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle56 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle57 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle59 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle60 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle61 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle62 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle63 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle64 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle65 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle66 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->mainButton = (gcnew System::Windows::Forms::Button());
			this->N_textBox = (gcnew System::Windows::Forms::TextBox());
			this->M_textBox = (gcnew System::Windows::Forms::TextBox());
			this->N_label = (gcnew System::Windows::Forms::Label());
			this->M_label = (gcnew System::Windows::Forms::Label());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->R_textBox = (gcnew System::Windows::Forms::TextBox());
			this->R_label = (gcnew System::Windows::Forms::Label());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->dataGridView_table = (gcnew System::Windows::Forms::DataGridView());
			this->Column_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->table_label = (gcnew System::Windows::Forms::Label());
			this->maxError_label = (gcnew System::Windows::Forms::Label());
			this->maxError_textBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_table))->BeginInit();
			this->SuspendLayout();
			// 
			// mainButton
			// 
			this->mainButton->Location = System::Drawing::Point(42, 156);
			this->mainButton->Name = L"mainButton";
			this->mainButton->Size = System::Drawing::Size(196, 52);
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
			this->N_label->Location = System::Drawing::Point(215, 33);
			this->N_label->Name = L"N_label";
			this->N_label->Size = System::Drawing::Size(91, 13);
			this->N_label->TabIndex = 5;
			this->N_label->Text = L"Число лампочек";
			// 
			// M_label
			// 
			this->M_label->AutoSize = true;
			this->M_label->Location = System::Drawing::Point(192, 60);
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
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->column1,
					this->column2, this->column3, this->Column4
			});
			this->dataGridView->Location = System::Drawing::Point(42, 214);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			dataGridViewCellStyle58->NullValue = nullptr;
			this->dataGridView->RowsDefaultCellStyle = dataGridViewCellStyle58;
			this->dataGridView->Size = System::Drawing::Size(264, 238);
			this->dataGridView->TabIndex = 7;
			// 
			// column1
			// 
			this->column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->column1->HeaderText = L"y_i";
			this->column1->Name = L"column1";
			this->column1->ReadOnly = true;
			this->column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->column1->Width = 45;
			// 
			// column2
			// 
			this->column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->column2->HeaderText = L"n_i";
			this->column2->Name = L"column2";
			this->column2->ReadOnly = true;
			this->column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->column2->Width = 45;
			// 
			// column3
			// 
			this->column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			dataGridViewCellStyle56->Format = L"N4";
			dataGridViewCellStyle56->NullValue = nullptr;
			this->column3->DefaultCellStyle = dataGridViewCellStyle56;
			this->column3->HeaderText = L"n_i / n";
			this->column3->Name = L"column3";
			this->column3->ReadOnly = true;
			this->column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->column3->Width = 65;
			// 
			// Column4
			// 
			this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			dataGridViewCellStyle57->Format = L"N4";
			dataGridViewCellStyle57->NullValue = nullptr;
			this->Column4->DefaultCellStyle = dataGridViewCellStyle57;
			this->Column4->HeaderText = L"p( y_i )";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column4->Width = 65;
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
			this->R_label->Location = System::Drawing::Point(207, 87);
			this->R_label->Name = L"R_label";
			this->R_label->Size = System::Drawing::Size(99, 13);
			this->R_label->TabIndex = 9;
			this->R_label->Text = L"Число выбранных";
			// 
			// delete_button
			// 
			this->delete_button->Location = System::Drawing::Point(244, 156);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(62, 52);
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
			this->label->Location = System::Drawing::Point(185, 114);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(121, 13);
			this->label->TabIndex = 12;
			this->label->Text = L"Число экспериментов";
			// 
			// dataGridView_table
			// 
			this->dataGridView_table->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column_1,
					this->Column_2, this->Column_3, this->Column_4, this->Column_5, this->Column_6, this->Column_7, this->Column_8
			});
			this->dataGridView_table->Location = System::Drawing::Point(343, 60);
			this->dataGridView_table->Name = L"dataGridView_table";
			this->dataGridView_table->Size = System::Drawing::Size(460, 46);
			this->dataGridView_table->TabIndex = 13;
			// 
			// Column_1
			// 
			dataGridViewCellStyle59->Format = L"N2";
			dataGridViewCellStyle59->NullValue = nullptr;
			this->Column_1->DefaultCellStyle = dataGridViewCellStyle59;
			this->Column_1->HeaderText = L"M";
			this->Column_1->Name = L"Column_1";
			this->Column_1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_1->Width = 50;
			// 
			// Column_2
			// 
			dataGridViewCellStyle60->Format = L"N2";
			dataGridViewCellStyle60->NullValue = nullptr;
			this->Column_2->DefaultCellStyle = dataGridViewCellStyle60;
			this->Column_2->HeaderText = L"M\'";
			this->Column_2->Name = L"Column_2";
			this->Column_2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_2->Width = 50;
			// 
			// Column_3
			// 
			this->Column_3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			dataGridViewCellStyle61->Format = L"N5";
			dataGridViewCellStyle61->NullValue = nullptr;
			this->Column_3->DefaultCellStyle = dataGridViewCellStyle61;
			this->Column_3->HeaderText = L"|M-M\'|";
			this->Column_3->Name = L"Column_3";
			this->Column_3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_3->Width = 59;
			// 
			// Column_4
			// 
			dataGridViewCellStyle62->Format = L"N2";
			dataGridViewCellStyle62->NullValue = nullptr;
			this->Column_4->DefaultCellStyle = dataGridViewCellStyle62;
			this->Column_4->HeaderText = L"D";
			this->Column_4->Name = L"Column_4";
			this->Column_4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_4->Width = 50;
			// 
			// Column_5
			// 
			dataGridViewCellStyle63->Format = L"N2";
			dataGridViewCellStyle63->NullValue = nullptr;
			this->Column_5->DefaultCellStyle = dataGridViewCellStyle63;
			this->Column_5->HeaderText = L"D\'";
			this->Column_5->Name = L"Column_5";
			this->Column_5->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_5->Width = 50;
			// 
			// Column_6
			// 
			this->Column_6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			dataGridViewCellStyle64->Format = L"N5";
			dataGridViewCellStyle64->NullValue = nullptr;
			this->Column_6->DefaultCellStyle = dataGridViewCellStyle64;
			this->Column_6->HeaderText = L"|D-D\'|";
			this->Column_6->Name = L"Column_6";
			this->Column_6->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_6->Width = 57;
			// 
			// Column_7
			// 
			dataGridViewCellStyle65->Format = L"N2";
			dataGridViewCellStyle65->NullValue = nullptr;
			this->Column_7->DefaultCellStyle = dataGridViewCellStyle65;
			this->Column_7->HeaderText = L"Me";
			this->Column_7->Name = L"Column_7";
			this->Column_7->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_7->Width = 50;
			// 
			// Column_8
			// 
			dataGridViewCellStyle66->NullValue = nullptr;
			this->Column_8->DefaultCellStyle = dataGridViewCellStyle66;
			this->Column_8->HeaderText = L"R";
			this->Column_8->Name = L"Column_8";
			this->Column_8->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_8->Width = 50;
			// 
			// table_label
			// 
			this->table_label->AutoSize = true;
			this->table_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->table_label->Location = System::Drawing::Point(475, 34);
			this->table_label->Name = L"table_label";
			this->table_label->Size = System::Drawing::Size(183, 17);
			this->table_label->TabIndex = 14;
			this->table_label->Text = L"Числовые характеристики";
			// 
			// maxError_label
			// 
			this->maxError_label->AutoSize = true;
			this->maxError_label->Location = System::Drawing::Point(452, 114);
			this->maxError_label->Name = L"maxError_label";
			this->maxError_label->Size = System::Drawing::Size(230, 13);
			this->maxError_label->TabIndex = 15;
			this->maxError_label->Text = L"Максимальное отклонение | n_i/n - p(y_i) | = ";
			// 
			// maxError_textBox
			// 
			this->maxError_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->maxError_textBox->Location = System::Drawing::Point(688, 112);
			this->maxError_textBox->Name = L"maxError_textBox";
			this->maxError_textBox->Size = System::Drawing::Size(115, 20);
			this->maxError_textBox->TabIndex = 16;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 479);
			this->Controls->Add(this->maxError_textBox);
			this->Controls->Add(this->maxError_label);
			this->Controls->Add(this->table_label);
			this->Controls->Add(this->dataGridView_table);
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
			this->Text = L"Лаб. работа: моделирование случайной величины - вариант 15";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void mainButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void delete_button_Click(System::Object^  sender, System::EventArgs^  e);

	protected: 
		double GetExpectedValue(); // математическое ожидание по проведенным экспериментам
		double GetDispersion();	   // дисперсия по проведенным экспериментам
		double GetMedian(); 	   // выборочная медиана
		double GetMaxError();	   // максимальное отклонение частот от вероятностей

	// расчет основных характеристик на основе проведенных экспериментов
		void CalculateCharacteristics();
	};
}
