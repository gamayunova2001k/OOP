#include "GraphicsPoints.h"

#pragma once

namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button_puz;
	private: System::Windows::Forms::Button^ button_graph;
	private: System::Windows::Forms::Button^ button_gist;

	private: GraphicsPoints ClassObj;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_gist = (gcnew System::Windows::Forms::Button());
			this->button_puz = (gcnew System::Windows::Forms::Button());
			this->button_graph = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->справкаToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(882, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(118, 24);
			this->справкаToolStripMenuItem->Text = L"О программе";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::СправкаToolStripMenuItem_Click);
			// 
			// button_exit
			// 
			this->button_exit->Location = System::Drawing::Point(365, 490);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(153, 40);
			this->button_exit->TabIndex = 2;
			this->button_exit->Text = L"Выйти";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &MyForm::Button_exit_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(12, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(600, 452);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_gist);
			this->groupBox2->Controls->Add(this->button_puz);
			this->groupBox2->Controls->Add(this->button_graph);
			this->groupBox2->Location = System::Drawing::Point(618, 32);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(252, 197);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Действия";
			// 
			// button_gist
			// 
			this->button_gist->Location = System::Drawing::Point(6, 39);
			this->button_gist->Name = L"button_gist";
			this->button_gist->Size = System::Drawing::Size(240, 40);
			this->button_gist->TabIndex = 6;
			this->button_gist->Text = L"Отобразить гистограмму";
			this->button_gist->UseVisualStyleBackColor = true;
			this->button_gist->Click += gcnew System::EventHandler(this, &MyForm::Button_gist_Click);
			// 
			// button_puz
			// 
			this->button_puz->Location = System::Drawing::Point(6, 131);
			this->button_puz->Name = L"button_puz";
			this->button_puz->Size = System::Drawing::Size(240, 60);
			this->button_puz->TabIndex = 5;
			this->button_puz->Text = L"Отобразить пузырьковую диаграмму";
			this->button_puz->UseVisualStyleBackColor = true;
			this->button_puz->Click += gcnew System::EventHandler(this, &MyForm::Button_puz_Click_1);
			// 
			// button_graph
			// 
			this->button_graph->Location = System::Drawing::Point(6, 85);
			this->button_graph->Name = L"button_graph";
			this->button_graph->Size = System::Drawing::Size(240, 40);
			this->button_graph->TabIndex = 3;
			this->button_graph->Text = L"Отобразить график";
			this->button_graph->UseVisualStyleBackColor = true;
			this->button_graph->Click += gcnew System::EventHandler(this, &MyForm::Button_graph_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(882, 542);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №4";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void СправкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Программа для работы с графическими изображениями Гамаюновой К. Д., КТбо1-9.", "О программе");
	}
	private: System::Void Button_gist_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ClassObj.Paint_Bar_Chart(groupBox1);
	}
	private: System::Void Button_graph_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ClassObj.Paint_Graphics(groupBox1);
	}
	private: System::Void Button_puz_Click_1(System::Object^ sender, System::EventArgs^ e) 
	{
		ClassObj.Paint_Buble(groupBox1);
	}
	private: System::Void Button_exit_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
};
}
