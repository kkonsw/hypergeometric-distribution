#pragma once

#include <vector>
#include <algorithm>

#include "Experiment.h"
#include "Computation.h"

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
        int totalExperiments;  // число экспериментов
		std::vector<int> *results;		   // все полученные значения СВ
		std::vector<int> *expandedResults; // все полученные значения СВ (с повторами)
		std::vector<double> *frequencies;  // частоты полученных значений СВ
		int rows;		// число строк в таблице
		int count;		// число проведенных экспериментов
        int k;          // число интервалов
        std::vector<double> *z; // границы интервалов разбиения
        std::vector<double> *q; // теоретические вероятности
        double alpha;   // уровень значимости

	private: System::Windows::Forms::DataGridView^  dataGridView;		
	private: System::Windows::Forms::TextBox^  R_textBox;
	private: System::Windows::Forms::Label^  R_label;			 
	private: System::Windows::Forms::Button^  delete_button;		 
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Label^  label;			 
	private: System::Windows::Forms::DataGridView^  dataGridView_table;
	private: System::Windows::Forms::Label^  table_label;
	private: System::Windows::Forms::Label^  maxError_label;
	private: System::Windows::Forms::TextBox^  maxError_textBox;
	private: System::Windows::Forms::Button^  mainButton;
	private: System::Windows::Forms::TextBox^  N_textBox;
	private: System::Windows::Forms::Label^  N_label;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart;
	private: System::Windows::Forms::Label^  graphics_label;
	private: System::Windows::Forms::Label^  divergency_label;
	private: System::Windows::Forms::TextBox^  divergency_textBox;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_8;
	private: System::Windows::Forms::GroupBox^  groupBox_experiment;
    private: System::Windows::Forms::TabControl^  tabControl1;
    private: System::Windows::Forms::TabPage^  tabPage1;
    private: System::Windows::Forms::TabPage^  tabPage2;
    private: System::Windows::Forms::Label^  label_distribution;
    private: System::Windows::Forms::TextBox^  M_textBox;
    private: System::Windows::Forms::Label^  label_alpha;
    private: System::Windows::Forms::Label^  label_intervals;
    private: System::Windows::Forms::GroupBox^  groupBox_distribution;
    private: System::Windows::Forms::TextBox^  textBox_alpha;
    private: System::Windows::Forms::TextBox^  textBox_intervals;
    private: System::Windows::Forms::Button^  button_distribution;
    private: System::Windows::Forms::Button^  button_save;
    private: System::Windows::Forms::Label^  label_mode;
    private: System::Windows::Forms::RadioButton^  radioButton2;
    private: System::Windows::Forms::RadioButton^  radioButton1;
    private: System::Windows::Forms::DataGridView^  dataGridView_intervals;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_index;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_intervals;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_n;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_q;
    private: System::Windows::Forms::GroupBox^  groupBox_results;
    private: System::Windows::Forms::TextBox^  textBox_R0;
    private: System::Windows::Forms::Label^  label_R0;
    private: System::Windows::Forms::TextBox^  textBox_F;
    private: System::Windows::Forms::Label^  label_F;
    private: System::Windows::Forms::Label^  label_hypothesis;
    private: System::Windows::Forms::Label^  M_label;

	public:
		MainForm(void)
		{
			experiment = new Experiment();
            totalExperiments = 0;
			results = new std::vector<int>;
			expandedResults = new std::vector<int>;
			frequencies = new std::vector<double>;
            z = new std::vector<double>;
            q = new std::vector<double>;
			count = 0; 
			rows = 0;
            k = 0;
            alpha = 0.0;

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
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle34 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle35 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle36 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle37 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
            System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->mainButton = (gcnew System::Windows::Forms::Button());
            this->N_textBox = (gcnew System::Windows::Forms::TextBox());
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
            this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->graphics_label = (gcnew System::Windows::Forms::Label());
            this->divergency_label = (gcnew System::Windows::Forms::Label());
            this->divergency_textBox = (gcnew System::Windows::Forms::TextBox());
            this->groupBox_experiment = (gcnew System::Windows::Forms::GroupBox());
            this->M_textBox = (gcnew System::Windows::Forms::TextBox());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->groupBox_results = (gcnew System::Windows::Forms::GroupBox());
            this->label_hypothesis = (gcnew System::Windows::Forms::Label());
            this->textBox_F = (gcnew System::Windows::Forms::TextBox());
            this->label_F = (gcnew System::Windows::Forms::Label());
            this->textBox_R0 = (gcnew System::Windows::Forms::TextBox());
            this->label_R0 = (gcnew System::Windows::Forms::Label());
            this->dataGridView_intervals = (gcnew System::Windows::Forms::DataGridView());
            this->column_index = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->column_intervals = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->column_n = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->column_q = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->button_distribution = (gcnew System::Windows::Forms::Button());
            this->groupBox_distribution = (gcnew System::Windows::Forms::GroupBox());
            this->button_save = (gcnew System::Windows::Forms::Button());
            this->label_mode = (gcnew System::Windows::Forms::Label());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
            this->textBox_alpha = (gcnew System::Windows::Forms::TextBox());
            this->label_intervals = (gcnew System::Windows::Forms::Label());
            this->textBox_intervals = (gcnew System::Windows::Forms::TextBox());
            this->label_alpha = (gcnew System::Windows::Forms::Label());
            this->label_distribution = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_table))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
            this->groupBox_experiment->SuspendLayout();
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->tabPage2->SuspendLayout();
            this->groupBox_results->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_intervals))->BeginInit();
            this->groupBox_distribution->SuspendLayout();
            this->SuspendLayout();
            // 
            // mainButton
            // 
            this->mainButton->BackColor = System::Drawing::Color::WhiteSmoke;
            this->mainButton->Location = System::Drawing::Point(32, 228);
            this->mainButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->mainButton->Name = L"mainButton";
            this->mainButton->Size = System::Drawing::Size(295, 80);
            this->mainButton->TabIndex = 0;
            this->mainButton->Text = L"Получить результат эксперимента (число перегоревших лампочек из числа выбранных)";
            this->mainButton->UseVisualStyleBackColor = false;
            this->mainButton->Click += gcnew System::EventHandler(this, &MainForm::mainButton_Click);
            // 
            // N_textBox
            // 
            this->N_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->N_textBox->Location = System::Drawing::Point(7, 34);
            this->N_textBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->N_textBox->Name = L"N_textBox";
            this->N_textBox->Size = System::Drawing::Size(130, 26);
            this->N_textBox->TabIndex = 2;
            this->N_textBox->Text = L"10";
            // 
            // N_label
            // 
            this->N_label->AutoSize = true;
            this->N_label->Location = System::Drawing::Point(251, 36);
            this->N_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->N_label->Name = L"N_label";
            this->N_label->Size = System::Drawing::Size(135, 20);
            this->N_label->TabIndex = 5;
            this->N_label->Text = L"Число лампочек";
            // 
            // M_label
            // 
            this->M_label->AutoSize = true;
            this->M_label->Location = System::Drawing::Point(217, 72);
            this->M_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->M_label->Name = L"M_label";
            this->M_label->Size = System::Drawing::Size(169, 20);
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
            this->dataGridView->Location = System::Drawing::Point(32, 318);
            this->dataGridView->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->dataGridView->Name = L"dataGridView";
            this->dataGridView->ReadOnly = true;
            dataGridViewCellStyle29->NullValue = nullptr;
            this->dataGridView->RowsDefaultCellStyle = dataGridViewCellStyle29;
            this->dataGridView->Size = System::Drawing::Size(404, 356);
            this->dataGridView->TabIndex = 7;
            // 
            // column1
            // 
            this->column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
            this->column1->HeaderText = L"y_i";
            this->column1->Name = L"column1";
            this->column1->ReadOnly = true;
            this->column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->column1->Width = 90;
            // 
            // column2
            // 
            this->column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
            this->column2->HeaderText = L"n_i";
            this->column2->Name = L"column2";
            this->column2->ReadOnly = true;
            this->column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->column2->Width = 90;
            // 
            // column3
            // 
            this->column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
            dataGridViewCellStyle27->Format = L"N4";
            dataGridViewCellStyle27->NullValue = nullptr;
            this->column3->DefaultCellStyle = dataGridViewCellStyle27;
            this->column3->HeaderText = L"n_i / n";
            this->column3->Name = L"column3";
            this->column3->ReadOnly = true;
            this->column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->column3->Width = 90;
            // 
            // Column4
            // 
            this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
            dataGridViewCellStyle28->Format = L"N4";
            dataGridViewCellStyle28->NullValue = nullptr;
            this->Column4->DefaultCellStyle = dataGridViewCellStyle28;
            this->Column4->HeaderText = L"p( y_i )";
            this->Column4->Name = L"Column4";
            this->Column4->ReadOnly = true;
            this->Column4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column4->Width = 90;
            // 
            // R_textBox
            // 
            this->R_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->R_textBox->Location = System::Drawing::Point(7, 106);
            this->R_textBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->R_textBox->Name = L"R_textBox";
            this->R_textBox->Size = System::Drawing::Size(130, 26);
            this->R_textBox->TabIndex = 8;
            this->R_textBox->Text = L"5";
            // 
            // R_label
            // 
            this->R_label->AutoSize = true;
            this->R_label->Location = System::Drawing::Point(242, 108);
            this->R_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->R_label->Name = L"R_label";
            this->R_label->Size = System::Drawing::Size(144, 20);
            this->R_label->TabIndex = 9;
            this->R_label->Text = L"Число выбранных";
            // 
            // delete_button
            // 
            this->delete_button->BackColor = System::Drawing::Color::WhiteSmoke;
            this->delete_button->Location = System::Drawing::Point(335, 228);
            this->delete_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->delete_button->Name = L"delete_button";
            this->delete_button->Size = System::Drawing::Size(101, 80);
            this->delete_button->TabIndex = 10;
            this->delete_button->Text = L"Очистить";
            this->delete_button->UseVisualStyleBackColor = false;
            this->delete_button->Click += gcnew System::EventHandler(this, &MainForm::delete_button_Click);
            // 
            // textBox
            // 
            this->textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->textBox->Location = System::Drawing::Point(7, 141);
            this->textBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->textBox->Name = L"textBox";
            this->textBox->Size = System::Drawing::Size(130, 26);
            this->textBox->TabIndex = 11;
            this->textBox->Text = L"100";
            // 
            // label
            // 
            this->label->AutoSize = true;
            this->label->Location = System::Drawing::Point(208, 141);
            this->label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label->Name = L"label";
            this->label->Size = System::Drawing::Size(178, 20);
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
            this->dataGridView_table->Location = System::Drawing::Point(549, 58);
            this->dataGridView_table->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->dataGridView_table->Name = L"dataGridView_table";
            this->dataGridView_table->RowHeadersVisible = false;
            this->dataGridView_table->Size = System::Drawing::Size(631, 61);
            this->dataGridView_table->TabIndex = 13;
            // 
            // Column_1
            // 
            dataGridViewCellStyle30->Format = L"N2";
            dataGridViewCellStyle30->NullValue = nullptr;
            this->Column_1->DefaultCellStyle = dataGridViewCellStyle30;
            this->Column_1->HeaderText = L"M";
            this->Column_1->Name = L"Column_1";
            this->Column_1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column_1->Width = 75;
            // 
            // Column_2
            // 
            dataGridViewCellStyle31->Format = L"N2";
            dataGridViewCellStyle31->NullValue = nullptr;
            this->Column_2->DefaultCellStyle = dataGridViewCellStyle31;
            this->Column_2->HeaderText = L"M\'";
            this->Column_2->Name = L"Column_2";
            this->Column_2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column_2->Width = 75;
            // 
            // Column_3
            // 
            dataGridViewCellStyle32->Format = L"N5";
            dataGridViewCellStyle32->NullValue = nullptr;
            this->Column_3->DefaultCellStyle = dataGridViewCellStyle32;
            this->Column_3->HeaderText = L"|M-M\'|";
            this->Column_3->Name = L"Column_3";
            this->Column_3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column_3->Width = 89;
            // 
            // Column_4
            // 
            dataGridViewCellStyle33->Format = L"N2";
            dataGridViewCellStyle33->NullValue = nullptr;
            this->Column_4->DefaultCellStyle = dataGridViewCellStyle33;
            this->Column_4->HeaderText = L"D";
            this->Column_4->Name = L"Column_4";
            this->Column_4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column_4->Width = 75;
            // 
            // Column_5
            // 
            dataGridViewCellStyle34->Format = L"N2";
            dataGridViewCellStyle34->NullValue = nullptr;
            this->Column_5->DefaultCellStyle = dataGridViewCellStyle34;
            this->Column_5->HeaderText = L"D\'";
            this->Column_5->Name = L"Column_5";
            this->Column_5->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column_5->Width = 75;
            // 
            // Column_6
            // 
            dataGridViewCellStyle35->Format = L"N5";
            dataGridViewCellStyle35->NullValue = nullptr;
            this->Column_6->DefaultCellStyle = dataGridViewCellStyle35;
            this->Column_6->HeaderText = L"|D-D\'|";
            this->Column_6->Name = L"Column_6";
            this->Column_6->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column_6->Width = 87;
            // 
            // Column_7
            // 
            dataGridViewCellStyle36->Format = L"N2";
            dataGridViewCellStyle36->NullValue = nullptr;
            this->Column_7->DefaultCellStyle = dataGridViewCellStyle36;
            this->Column_7->HeaderText = L"Me";
            this->Column_7->Name = L"Column_7";
            this->Column_7->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column_7->Width = 75;
            // 
            // Column_8
            // 
            dataGridViewCellStyle37->NullValue = nullptr;
            this->Column_8->DefaultCellStyle = dataGridViewCellStyle37;
            this->Column_8->HeaderText = L"R";
            this->Column_8->Name = L"Column_8";
            this->Column_8->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Column_8->Width = 75;
            // 
            // table_label
            // 
            this->table_label->AutoSize = true;
            this->table_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
            this->table_label->Location = System::Drawing::Point(700, 22);
            this->table_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->table_label->Name = L"table_label";
            this->table_label->Size = System::Drawing::Size(283, 25);
            this->table_label->TabIndex = 14;
            this->table_label->Text = L"Числовые характеристики:";
            // 
            // maxError_label
            // 
            this->maxError_label->AutoSize = true;
            this->maxError_label->Location = System::Drawing::Point(834, 134);
            this->maxError_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->maxError_label->Name = L"maxError_label";
            this->maxError_label->Size = System::Drawing::Size(166, 20);
            this->maxError_label->TabIndex = 15;
            this->maxError_label->Text = L"Макс. отклонение  = ";
            // 
            // maxError_textBox
            // 
            this->maxError_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->maxError_textBox->Location = System::Drawing::Point(1008, 132);
            this->maxError_textBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->maxError_textBox->Name = L"maxError_textBox";
            this->maxError_textBox->Size = System::Drawing::Size(172, 26);
            this->maxError_textBox->TabIndex = 16;
            // 
            // chart
            // 
            this->chart->BackSecondaryColor = System::Drawing::Color::White;
            this->chart->BorderlineColor = System::Drawing::Color::Black;
            this->chart->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
            chartArea3->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
            chartArea3->AxisX->Minimum = 0;
            chartArea3->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
            chartArea3->AxisY->Maximum = 1.2;
            chartArea3->BackColor = System::Drawing::Color::White;
            chartArea3->Name = L"ChartArea1";
            this->chart->ChartAreas->Add(chartArea3);
            legend3->Enabled = false;
            legend3->MaximumAutoSize = 80;
            legend3->Name = L"Legend1";
            legend3->Position->Auto = false;
            legend3->Position->Height = 15;
            legend3->Position->Width = 30.88671F;
            legend3->Position->X = 15;
            legend3->Position->Y = 5;
            this->chart->Legends->Add(legend3);
            this->chart->Location = System::Drawing::Point(549, 228);
            this->chart->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->chart->Name = L"chart";
            series5->BorderWidth = 2;
            series5->ChartArea = L"ChartArea1";
            series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
            series5->Legend = L"Legend1";
            series5->LegendText = L"Теоретическая";
            series5->Name = L"Series1";
            series6->BorderWidth = 2;
            series6->ChartArea = L"ChartArea1";
            series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
            series6->Legend = L"Legend1";
            series6->LegendText = L"Выборочная";
            series6->Name = L"Series2";
            series6->YValuesPerPoint = 2;
            this->chart->Series->Add(series5);
            this->chart->Series->Add(series6);
            this->chart->Size = System::Drawing::Size(631, 446);
            this->chart->TabIndex = 17;
            this->chart->Text = L"chart";
            // 
            // graphics_label
            // 
            this->graphics_label->AutoSize = true;
            this->graphics_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
            this->graphics_label->Location = System::Drawing::Point(544, 182);
            this->graphics_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->graphics_label->Name = L"graphics_label";
            this->graphics_label->Size = System::Drawing::Size(266, 25);
            this->graphics_label->TabIndex = 18;
            this->graphics_label->Text = L"Функции распределения:";
            // 
            // divergency_label
            // 
            this->divergency_label->AutoSize = true;
            this->divergency_label->Location = System::Drawing::Point(834, 187);
            this->divergency_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->divergency_label->Name = L"divergency_label";
            this->divergency_label->Size = System::Drawing::Size(170, 20);
            this->divergency_label->TabIndex = 19;
            this->divergency_label->Text = L"Мера расхождения = ";
            // 
            // divergency_textBox
            // 
            this->divergency_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->divergency_textBox->Location = System::Drawing::Point(1008, 185);
            this->divergency_textBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->divergency_textBox->Name = L"divergency_textBox";
            this->divergency_textBox->Size = System::Drawing::Size(172, 26);
            this->divergency_textBox->TabIndex = 20;
            // 
            // groupBox_experiment
            // 
            this->groupBox_experiment->Controls->Add(this->N_textBox);
            this->groupBox_experiment->Controls->Add(this->N_label);
            this->groupBox_experiment->Controls->Add(this->M_textBox);
            this->groupBox_experiment->Controls->Add(this->M_label);
            this->groupBox_experiment->Controls->Add(this->R_textBox);
            this->groupBox_experiment->Controls->Add(this->textBox);
            this->groupBox_experiment->Controls->Add(this->R_label);
            this->groupBox_experiment->Controls->Add(this->label);
            this->groupBox_experiment->Location = System::Drawing::Point(32, 22);
            this->groupBox_experiment->Name = L"groupBox_experiment";
            this->groupBox_experiment->Size = System::Drawing::Size(404, 185);
            this->groupBox_experiment->TabIndex = 21;
            this->groupBox_experiment->TabStop = false;
            this->groupBox_experiment->Text = L"Параметры эксперимента";
            // 
            // M_textBox
            // 
            this->M_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->M_textBox->Location = System::Drawing::Point(7, 70);
            this->M_textBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->M_textBox->Name = L"M_textBox";
            this->M_textBox->Size = System::Drawing::Size(130, 26);
            this->M_textBox->TabIndex = 3;
            this->M_textBox->Text = L"5";
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Location = System::Drawing::Point(2, 2);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(1245, 733);
            this->tabControl1->TabIndex = 22;
            // 
            // tabPage1
            // 
            this->tabPage1->BackColor = System::Drawing::Color::Transparent;
            this->tabPage1->Controls->Add(this->groupBox_experiment);
            this->tabPage1->Controls->Add(this->divergency_textBox);
            this->tabPage1->Controls->Add(this->mainButton);
            this->tabPage1->Controls->Add(this->graphics_label);
            this->tabPage1->Controls->Add(this->divergency_label);
            this->tabPage1->Controls->Add(this->chart);
            this->tabPage1->Controls->Add(this->delete_button);
            this->tabPage1->Controls->Add(this->dataGridView_table);
            this->tabPage1->Controls->Add(this->dataGridView);
            this->tabPage1->Controls->Add(this->table_label);
            this->tabPage1->Controls->Add(this->maxError_textBox);
            this->tabPage1->Controls->Add(this->maxError_label);
            this->tabPage1->Location = System::Drawing::Point(4, 29);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(1237, 700);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Эксперимент";
            // 
            // tabPage2
            // 
            this->tabPage2->BackColor = System::Drawing::Color::Transparent;
            this->tabPage2->Controls->Add(this->groupBox_results);
            this->tabPage2->Controls->Add(this->dataGridView_intervals);
            this->tabPage2->Controls->Add(this->button_distribution);
            this->tabPage2->Controls->Add(this->groupBox_distribution);
            this->tabPage2->Controls->Add(this->label_distribution);
            this->tabPage2->Location = System::Drawing::Point(4, 29);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(1237, 700);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Распределение";
            // 
            // groupBox_results
            // 
            this->groupBox_results->Controls->Add(this->label_hypothesis);
            this->groupBox_results->Controls->Add(this->textBox_F);
            this->groupBox_results->Controls->Add(this->label_F);
            this->groupBox_results->Controls->Add(this->textBox_R0);
            this->groupBox_results->Controls->Add(this->label_R0);
            this->groupBox_results->Location = System::Drawing::Point(920, 130);
            this->groupBox_results->Name = L"groupBox_results";
            this->groupBox_results->Size = System::Drawing::Size(264, 375);
            this->groupBox_results->TabIndex = 8;
            this->groupBox_results->TabStop = false;
            this->groupBox_results->Text = L"Результаты";
            // 
            // label_hypothesis
            // 
            this->label_hypothesis->AutoSize = true;
            this->label_hypothesis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label_hypothesis->Location = System::Drawing::Point(32, 178);
            this->label_hypothesis->Name = L"label_hypothesis";
            this->label_hypothesis->Size = System::Drawing::Size(17, 25);
            this->label_hypothesis->TabIndex = 4;
            this->label_hypothesis->Text = L" ";
            // 
            // textBox_F
            // 
            this->textBox_F->Location = System::Drawing::Point(102, 98);
            this->textBox_F->Name = L"textBox_F";
            this->textBox_F->Size = System::Drawing::Size(125, 26);
            this->textBox_F->TabIndex = 3;
            // 
            // label_F
            // 
            this->label_F->AutoSize = true;
            this->label_F->Location = System::Drawing::Point(22, 101);
            this->label_F->Name = L"label_F";
            this->label_F->Size = System::Drawing::Size(74, 20);
            this->label_F->TabIndex = 2;
            this->label_F->Text = L"F^(R0) = ";
            // 
            // textBox_R0
            // 
            this->textBox_R0->Location = System::Drawing::Point(102, 57);
            this->textBox_R0->Name = L"textBox_R0";
            this->textBox_R0->Size = System::Drawing::Size(125, 26);
            this->textBox_R0->TabIndex = 1;
            // 
            // label_R0
            // 
            this->label_R0->AutoSize = true;
            this->label_R0->Location = System::Drawing::Point(49, 60);
            this->label_R0->Name = L"label_R0";
            this->label_R0->Size = System::Drawing::Size(47, 20);
            this->label_R0->TabIndex = 0;
            this->label_R0->Text = L"R0 = ";
            // 
            // dataGridView_intervals
            // 
            this->dataGridView_intervals->BackgroundColor = System::Drawing::SystemColors::Control;
            this->dataGridView_intervals->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_intervals->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->column_index,
                    this->column_intervals, this->column_n, this->column_q
            });
            this->dataGridView_intervals->Location = System::Drawing::Point(509, 140);
            this->dataGridView_intervals->Name = L"dataGridView_intervals";
            this->dataGridView_intervals->RowHeadersVisible = false;
            this->dataGridView_intervals->RowTemplate->Height = 28;
            this->dataGridView_intervals->Size = System::Drawing::Size(355, 365);
            this->dataGridView_intervals->TabIndex = 7;
            // 
            // column_index
            // 
            this->column_index->HeaderText = L"z_i";
            this->column_index->Name = L"column_index";
            this->column_index->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->column_index->Width = 50;
            // 
            // column_intervals
            // 
            dataGridViewCellStyle38->Format = L"N2";
            dataGridViewCellStyle38->NullValue = nullptr;
            this->column_intervals->DefaultCellStyle = dataGridViewCellStyle38;
            this->column_intervals->HeaderText = L"Значение";
            this->column_intervals->Name = L"column_intervals";
            this->column_intervals->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            // 
            // column_n
            // 
            this->column_n->HeaderText = L"n_j";
            this->column_n->Name = L"column_n";
            this->column_n->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            // 
            // column_q
            // 
            dataGridViewCellStyle39->Format = L"N4";
            dataGridViewCellStyle39->NullValue = nullptr;
            this->column_q->DefaultCellStyle = dataGridViewCellStyle39;
            this->column_q->HeaderText = L"q_j";
            this->column_q->Name = L"column_q";
            this->column_q->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            // 
            // button_distribution
            // 
            this->button_distribution->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_distribution->Location = System::Drawing::Point(52, 434);
            this->button_distribution->Name = L"button_distribution";
            this->button_distribution->Size = System::Drawing::Size(410, 71);
            this->button_distribution->TabIndex = 5;
            this->button_distribution->Text = L"Проверка гипотезы";
            this->button_distribution->UseVisualStyleBackColor = false;
            this->button_distribution->Click += gcnew System::EventHandler(this, &MainForm::button_distribution_Click);
            // 
            // groupBox_distribution
            // 
            this->groupBox_distribution->Controls->Add(this->button_save);
            this->groupBox_distribution->Controls->Add(this->label_mode);
            this->groupBox_distribution->Controls->Add(this->radioButton2);
            this->groupBox_distribution->Controls->Add(this->radioButton1);
            this->groupBox_distribution->Controls->Add(this->textBox_alpha);
            this->groupBox_distribution->Controls->Add(this->label_intervals);
            this->groupBox_distribution->Controls->Add(this->textBox_intervals);
            this->groupBox_distribution->Controls->Add(this->label_alpha);
            this->groupBox_distribution->Location = System::Drawing::Point(52, 130);
            this->groupBox_distribution->Name = L"groupBox_distribution";
            this->groupBox_distribution->Size = System::Drawing::Size(410, 265);
            this->groupBox_distribution->TabIndex = 4;
            this->groupBox_distribution->TabStop = false;
            this->groupBox_distribution->Text = L"Параметры";
            // 
            // button_save
            // 
            this->button_save->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_save->Location = System::Drawing::Point(6, 183);
            this->button_save->Name = L"button_save";
            this->button_save->Size = System::Drawing::Size(209, 51);
            this->button_save->TabIndex = 8;
            this->button_save->Text = L"Сохранить";
            this->button_save->UseVisualStyleBackColor = false;
            this->button_save->Click += gcnew System::EventHandler(this, &MainForm::button_save_Click);
            // 
            // label_mode
            // 
            this->label_mode->AutoSize = true;
            this->label_mode->Location = System::Drawing::Point(6, 146);
            this->label_mode->Name = L"label_mode";
            this->label_mode->Size = System::Drawing::Size(213, 20);
            this->label_mode->TabIndex = 7;
            this->label_mode->Text = L"Выбор границ интервалов:";
            // 
            // radioButton2
            // 
            this->radioButton2->AutoSize = true;
            this->radioButton2->Location = System::Drawing::Point(246, 210);
            this->radioButton2->Name = L"radioButton2";
            this->radioButton2->Size = System::Drawing::Size(98, 24);
            this->radioButton2->TabIndex = 6;
            this->radioButton2->Text = L"Вручную";
            this->radioButton2->UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this->radioButton1->AutoSize = true;
            this->radioButton1->Checked = true;
            this->radioButton1->Location = System::Drawing::Point(246, 180);
            this->radioButton1->Name = L"radioButton1";
            this->radioButton1->Size = System::Drawing::Size(153, 24);
            this->radioButton1->TabIndex = 5;
            this->radioButton1->TabStop = true;
            this->radioButton1->Text = L"Автоматически";
            this->radioButton1->UseVisualStyleBackColor = true;
            // 
            // textBox_alpha
            // 
            this->textBox_alpha->Location = System::Drawing::Point(299, 101);
            this->textBox_alpha->Name = L"textBox_alpha";
            this->textBox_alpha->Size = System::Drawing::Size(100, 26);
            this->textBox_alpha->TabIndex = 4;
            this->textBox_alpha->Text = L"0,5";
            // 
            // label_intervals
            // 
            this->label_intervals->AutoSize = true;
            this->label_intervals->Location = System::Drawing::Point(6, 60);
            this->label_intervals->Name = L"label_intervals";
            this->label_intervals->Size = System::Drawing::Size(234, 20);
            this->label_intervals->TabIndex = 1;
            this->label_intervals->Text = L"Требуемое число интервалов";
            // 
            // textBox_intervals
            // 
            this->textBox_intervals->Location = System::Drawing::Point(299, 57);
            this->textBox_intervals->Name = L"textBox_intervals";
            this->textBox_intervals->Size = System::Drawing::Size(100, 26);
            this->textBox_intervals->TabIndex = 3;
            this->textBox_intervals->Text = L"5";
            // 
            // label_alpha
            // 
            this->label_alpha->AutoSize = true;
            this->label_alpha->Location = System::Drawing::Point(6, 104);
            this->label_alpha->Name = L"label_alpha";
            this->label_alpha->Size = System::Drawing::Size(167, 20);
            this->label_alpha->TabIndex = 2;
            this->label_alpha->Text = L"Уровень значимости";
            // 
            // label_distribution
            // 
            this->label_distribution->AutoSize = true;
            this->label_distribution->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->label_distribution->Location = System::Drawing::Point(57, 64);
            this->label_distribution->Name = L"label_distribution";
            this->label_distribution->Size = System::Drawing::Size(405, 26);
            this->label_distribution->TabIndex = 0;
            this->label_distribution->Text = L"Гипергеометрическое распределение:";
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(1248, 737);
            this->Controls->Add(this->tabControl1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->Name = L"MainForm";
            this->Text = L"Лаб. работа: моделирование случайной величины - вариант 15";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_table))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
            this->groupBox_experiment->ResumeLayout(false);
            this->groupBox_experiment->PerformLayout();
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tabPage1->PerformLayout();
            this->tabPage2->ResumeLayout(false);
            this->tabPage2->PerformLayout();
            this->groupBox_results->ResumeLayout(false);
            this->groupBox_results->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_intervals))->EndInit();
            this->groupBox_distribution->ResumeLayout(false);
            this->groupBox_distribution->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

	private: System::Void mainButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void delete_button_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_distribution_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_save_Click(System::Object^  sender, System::EventArgs^  e);

	protected: 
		double GetExpectedValue(); // математическое ожидание по проведенным экспериментам
		double GetDispersion();	   // дисперсия по проведенным экспериментам
		double GetMedian(); 	   // выборочная медиана
		double GetMaxError();	   // максимальное отклонение частот от вероятностей

	// расчет основных характеристик на основе проведенных экспериментов
		void CalculateCharacteristics();
		void DrawGraphics(); // построение графиков функций распределения
};
}
