#pragma once

namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class WinForm : public System::Windows::Forms::Form
	{
	public:
		WinForm(void)
		{
			InitializeComponent();
		}

		~WinForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ÒÔ‡‚Í‡ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_update;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_download;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ÕÓÏÂ;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ searchWord;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ words_sites;


	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ÒÔ‡‚Í‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ÕÓÏÂ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->searchWord = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->words_sites = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_download = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->Location = System::Drawing::Point(376, 276);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(153, 40);
			this->button_exit->TabIndex = 1;
			this->button_exit->Text = L"¬˚ÈÚË";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &WinForm::Button_Exit);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ÒÔ‡‚Í‡ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(906, 28);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ÒÔ‡‚Í‡ToolStripMenuItem
			// 
			this->ÒÔ‡‚Í‡ToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->ÒÔ‡‚Í‡ToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Name = L"ÒÔ‡‚Í‡ToolStripMenuItem";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Size = System::Drawing::Size(118, 24);
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Text = L"Œ ÔÓ„‡ÏÏÂ";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Click += gcnew System::EventHandler(this, &WinForm::—Ô‡‚Í‡ToolStripMenuItem_Click_1);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ÕÓÏÂ,
					this->searchWord, this->words_sites
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 31);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(684, 235);
			this->dataGridView1->TabIndex = 3;
			// 
			// ÕÓÏÂ
			// 
			this->ÕÓÏÂ->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->ÕÓÏÂ->FillWeight = 40;
			this->ÕÓÏÂ->HeaderText = L"π";
			this->ÕÓÏÂ->MinimumWidth = 6;
			this->ÕÓÏÂ->Name = L"ÕÓÏÂ";
			this->ÕÓÏÂ->Width = 40;
			// 
			// searchWord
			// 
			this->searchWord->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->searchWord->FillWeight = 130;
			this->searchWord->HeaderText = L"—ÎÓ‚Ó";
			this->searchWord->MinimumWidth = 6;
			this->searchWord->Name = L"searchWord";
			this->searchWord->Width = 140;
			// 
			// words_sites
			// 
			this->words_sites->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->words_sites->FillWeight = 260;
			this->words_sites->HeaderText = L"—‡ÈÚ";
			this->words_sites->MinimumWidth = 6;
			this->words_sites->Name = L"words_sites";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_delete);
			this->groupBox1->Controls->Add(this->button_update);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->button_download);
			this->groupBox1->Location = System::Drawing::Point(702, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(192, 235);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ƒÂÈÒÚ‚Ëˇ";
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(6, 180);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(180, 40);
			this->button_delete->TabIndex = 3;
			this->button_delete->Text = L"”‰‡ÎËÚ¸";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &WinForm::Button_delete);
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(6, 134);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(180, 40);
			this->button_update->TabIndex = 2;
			this->button_update->Text = L"»ÁÏÂÌËÚ¸";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &WinForm::Button_update);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(6, 88);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(180, 40);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"ƒÓ·‡‚ËÚ¸";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &WinForm::Button_add);
			// 
			// button_download
			// 
			this->button_download->Location = System::Drawing::Point(6, 30);
			this->button_download->Name = L"button_download";
			this->button_download->Size = System::Drawing::Size(180, 52);
			this->button_download->TabIndex = 0;
			this->button_download->Text = L"«‡„ÛÁËÚ¸ \r\n‰‡ÌÌ˚Â";
			this->button_download->UseVisualStyleBackColor = true;
			this->button_download->Click += gcnew System::EventHandler(this, &WinForm::Button_download);
			// 
			// WinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(906, 328);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"WinForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"À‡·. ‡·ÓÚ‡ π3";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button_Exit(System::Object^ sender, System::EventArgs^ e);
	private: System::Void —Ô‡‚Í‡ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_download(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_add(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_update(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_delete(System::Object^ sender, System::EventArgs^ e);
};
}
