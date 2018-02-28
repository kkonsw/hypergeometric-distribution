#pragma once
#include "RandomValue.h"

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
		RandomValue* Generator;

	public:
		MainForm(void)
		{
			Generator = new RandomValue();
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
			this->SuspendLayout();
			// 
			// mainButton
			// 
			this->mainButton->Location = System::Drawing::Point(29, 144);
			this->mainButton->Name = L"mainButton";
			this->mainButton->Size = System::Drawing::Size(196, 37);
			this->mainButton->TabIndex = 0;
			this->mainButton->Text = L"Получить значение случайной величины";
			this->mainButton->UseVisualStyleBackColor = true;
			this->mainButton->Click += gcnew System::EventHandler(this, &MainForm::mainButton_Click);
			// 
			// result_textBox
			// 
			this->result_textBox->Location = System::Drawing::Point(72, 187);
			this->result_textBox->Name = L"result_textBox";
			this->result_textBox->Size = System::Drawing::Size(153, 20);
			this->result_textBox->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(255, 256);
			this->Controls->Add(this->result_textBox);
			this->Controls->Add(this->mainButton);
			this->Name = L"MainForm";
			this->Text = L"Лаб. работа: моделирование случайной величины";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mainButton_Click(System::Object^  sender, System::EventArgs^  e) {
		result_textBox->Text = Generator->GetRandomValue().ToString();
	}
	};
}
