#include "pch.h"
#include "Windows.h"
#include "MyClass.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;

System::Void Lab2::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	MyClass ClassObj;
	ClassObject.AddNameToList("www.people-rights.ru/Alliance");
	this->listBox1->Items->Add("www.people-rights.ru/Alliance");
	ClassObject.AddNameToList("www.people-rights.ru/Union");
	this->listBox1->Items->Add("www.people-rights.ru/Union");
	ClassObject.AddNameToList("www.people-rights.ru/Ruts");
	this->listBox1->Items->Add("www.people-rights.ru/Ruts");
	ClassObject.AddNameToList("www.tea-house.ru/Dark");
	this->listBox1->Items->Add("www.tea-house.ru/Dark");
	ClassObject.AddNameToList("www.tobacco.ru/Dark");
	this->listBox1->Items->Add("www.tobacco.ru/Dark");
	ClassObject.AddNameToList("www.people-rights.ru/Dark");
	this->listBox1->Items->Add("www.people-rights.ru/Dark");
	ClassObject.AddNameToList("www.tobacco.ru/Side");
	this->listBox1->Items->Add("www.tobacco.ru/Side");
	ClassObject.AddNameToList("www.people-rights.ru/Side");
	this->listBox1->Items->Add("www.people-rights.ru/Side");
	ClassObject.AddNameToList("www.tobacco.ru/Musthave");
	this->listBox1->Items->Add("www.tobacco.ru/Musthave");
	ClassObject.AddNameToList("www.tea-house.ru/Curtis");
	this->listBox1->Items->Add("www.tea-house.ru/Curtis");
	ClassObject.AddNameToList("www.tea-house.ru/Greenfield");
	this->listBox1->Items->Add("www.tea-house.ru/Greenfield");
	ClassObject.AddNameToList("www.tea-house.ru/Tess");
	this->listBox1->Items->Add("www.tea-house.ru/Tess");
}

System::Void Lab2::MyForm::Button1_Click_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->listBox1->SelectedIndex >= 0)
	{
		String^ s = (String^)this->listBox1->SelectedItem;
		this->listBox1->Items->RemoveAt(this->listBox1->SelectedIndex);
		ClassObject.DelNameFromList(s);
	}
}

System::Void Lab2::MyForm::Button2_Click_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool IsCorrect = (this->textBox1->Text->Length > 0)
		&& (this->textBox1->Text->IndexOf('/') >= 0)
		&& (this->textBox1->Text->Length - this->textBox1 -> Text->IndexOf('/') > 1);
	if (IsCorrect)
	{
		ClassObject.AddNameToList(this->textBox1->Text);
		this->listBox1->Items->Add(this->textBox1->Text);
	}
	else
	{
		MessageBox::Show("Имя файла задано неверно!", "Ошибка", ::MessageBoxButtons::OK);	}
}

System::Void Lab2::MyForm::Button3_Click_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBox2->Text->Length > 0)
	{
		ArrayList^ al = ClassObject.GetSitesWithWords(this->textBox2 -> Text);
		this->listBox2->Items->Clear();
		for (int i = 0; i < al->Count; i++)
			this->listBox2->Items->Add(al[i]);
	}
}

System::Void Lab2::MyForm::Button4_Click_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}