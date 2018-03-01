#pragma once
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
		Experiment* experiment;
		int count = 0;
	public:
		MainForm(void)
		{
			experiment = new Experiment();
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
	private: System::Windows::Forms::TextBox^  result_textBox;
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
			this->mainButton = (gcnew System::Windows::Forms::Button());
			this->result_textBox = (gcnew System::Windows::Forms::TextBox());
			this->N_textBox = (gcnew System::Windows::Forms::TextBox());
			this->M_textBox = (gcnew System::Windows::Forms::TextBox());
			this->N_label = (gcnew System::Windows::Forms::Label());
			this->M_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// mainButton
			// 
			this->mainButton->Location = System::Drawing::Point(42, 144);
			this->mainButton->Name = L"mainButton";
			this->mainButton->Size = System::Drawing::Size(196, 37);
			this->mainButton->TabIndex = 0;
			this->mainButton->Text = L"Получить результат эксперимента (одна лампочка)";
			this->mainButton->UseVisualStyleBackColor = true;
			this->mainButton->Click += gcnew System::EventHandler(this, &MainForm::mainButton_Click);
			// 
			// result_textBox
			// 
			this->result_textBox->Location = System::Drawing::Point(148, 187);
			this->result_textBox->Name = L"result_textBox";
			this->result_textBox->Size = System::Drawing::Size(90, 20);
			this->result_textBox->TabIndex = 1;
			// 
			// N_textBox
			// 
			this->N_textBox->Location = System::Drawing::Point(29, 31);
			this->N_textBox->Name = L"N_textBox";
			this->N_textBox->Size = System::Drawing::Size(100, 20);
			this->N_textBox->TabIndex = 2;
			this->N_textBox->Text = L"100";
			// 
			// M_textBox
			// 
			this->M_textBox->Location = System::Drawing::Point(29, 58);
			this->M_textBox->Name = L"M_textBox";
			this->M_textBox->Size = System::Drawing::Size(100, 20);
			this->M_textBox->TabIndex = 3;
			this->M_textBox->Text = L"90";
			// 
			// N_label
			// 
			this->N_label->AutoSize = true;
			this->N_label->Location = System::Drawing::Point(147, 38);
			this->N_label->Name = L"N_label";
			this->N_label->Size = System::Drawing::Size(91, 13);
			this->N_label->TabIndex = 5;
			this->N_label->Text = L"Число лампочек";
			// 
			// M_label
			// 
			this->M_label->AutoSize = true;
			this->M_label->Location = System::Drawing::Point(147, 64);
			this->M_label->Name = L"M_label";
			this->M_label->Size = System::Drawing::Size(114, 13);
			this->M_label->TabIndex = 6;
			this->M_label->Text = L"Число перегоревших";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(310, 256);
			this->Controls->Add(this->M_label);
			this->Controls->Add(this->N_label);
			this->Controls->Add(this->M_textBox);
			this->Controls->Add(this->N_textBox);
			this->Controls->Add(this->result_textBox);
			this->Controls->Add(this->mainButton);
			this->Name = L"MainForm";
			this->Text = L"Лаб. работа: моделирование случайной величины";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mainButton_Click(System::Object^  sender, System::EventArgs^  e) {	
		experiment->SetAmountOfLightbulbs(System::Convert::ToInt32(N_textBox->Text));
		experiment->SetAmountOfDamaged(System::Convert::ToInt32(M_textBox->Text));
		count = 0;

		for (int i = 0; i < 10000; i++)
		count += experiment->GetOneBulb();

		//result_textBox->Text = experiment->GetOneBulb().ToString();
		result_textBox->Text = count.ToString();
	}
	};
}
