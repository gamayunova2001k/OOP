#pragma once

namespace Lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public
	ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm()
		{
			this->InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components) {
				delete components;
			}
		}

	public:
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
	private:
		System::Windows::Forms::Button^ button1_Click;
		System::Windows::Forms::Button^ button2_Click;
		System::Windows::Forms::Button^ button3_Click;
		System::Windows::Forms::Button^ button4_Click;
		System::Windows::Forms::ListBox^ listBox1;
		System::Windows::Forms::ListBox^ listBox2;
		System::ComponentModel::Container^ components;

	private: MyClass ClassObject;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1_Click = (gcnew System::Windows::Forms::Button());
			this->button2_Click = (gcnew System::Windows::Forms::Button());
			this->button3_Click = (gcnew System::Windows::Forms::Button());
			this->button4_Click = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 220);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(154, 28);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(327, 12);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(154, 28);
			this->textBox2->TabIndex = 5;
			// 
			// button1_Click
			// 
			this->button1_Click->AutoSize = true;
			this->button1_Click->Location = System::Drawing::Point(94, 256);
			this->button1_Click->Name = L"button1_Click";
			this->button1_Click->Size = System::Drawing::Size(84, 28);
			this->button1_Click->TabIndex = 11;
			this->button1_Click->Text = L"Удалить";
			this->button1_Click->UseVisualStyleBackColor = true;
			this->button1_Click->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click_Click);
			// 
			// button2_Click
			// 
			this->button2_Click->AutoSize = true;
			this->button2_Click->Location = System::Drawing::Point(172, 218);
			this->button2_Click->Name = L"button2_Click";
			this->button2_Click->Size = System::Drawing::Size(84, 30);
			this->button2_Click->TabIndex = 6;
			this->button2_Click->Text = L"Добавить";
			this->button2_Click->UseVisualStyleBackColor = true;
			this->button2_Click->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click_Click);
			// 
			// button3_Click
			// 
			this->button3_Click->Location = System::Drawing::Point(487, 12);
			this->button3_Click->Name = L"button3_Click";
			this->button3_Click->Size = System::Drawing::Size(84, 28);
			this->button3_Click->TabIndex = 14;
			this->button3_Click->Text = L"Найти";
			this->button3_Click->UseVisualStyleBackColor = true;
			this->button3_Click->Click += gcnew System::EventHandler(this, &MyForm::Button3_Click_Click);
			// 
			// button4_Click
			// 
			this->button4_Click->Location = System::Drawing::Point(248, 290);
			this->button4_Click->Name = L"button4_Click";
			this->button4_Click->Size = System::Drawing::Size(84, 28);
			this->button4_Click->TabIndex = 15;
			this->button4_Click->Text = L"Выйти";
			this->button4_Click->UseVisualStyleBackColor = true;
			this->button4_Click->Click += gcnew System::EventHandler(this, &MyForm::Button4_Click_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 18;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(244, 202);
			this->listBox1->TabIndex = 12;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 18;
			this->listBox2->Location = System::Drawing::Point(327, 46);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(244, 166);
			this->listBox2->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(583, 330);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1_Click);
			this->Controls->Add(this->button2_Click);
			this->Controls->Add(this->button3_Click);
			this->Controls->Add(this->button4_Click);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->listBox2);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лаб. работа №2";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Button4_Click_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button3_Click_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button2_Click_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button1_Click_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
};
}