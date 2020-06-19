#include "pch.h"
#include "WinForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

using namespace Lab3;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew WinForm);
	return 0;
}

System::Void Lab3::WinForm::�������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��������� ��� ������ � �� ���������� �. �., ����1-9. \r\n\n������ ��������: \r\n\"��������� ������\" - ��������� ������ �� �� � �������. \r\n\"��������\" - ��������� ������ � ��. \r\n\"��������\"  - �������� ������ ������ � ��. \r\n\"�������\" - ������� ������ ������ �� ��. \r\n\"�����\" - ��������� ���������.", "� ���������");

	return System::Void();
}

System::Void Lab3::WinForm::Button_download(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ querty = "SELECT * FROM [table]";
	OleDbCommand^ dbComand = gcnew OleDbCommand(querty, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();

	if (dbReader->HasRows == false) {
		MessageBox::Show("������ ���������� ������!","������!");
	}
	else
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["���"], dbReader["searchWord"], dbReader["sites"]);
		}
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void Lab3::WinForm::Button_add(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������ ������ ��� ����������
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ������ ��� ����������", "��������!");
		return;
	}

	//����� ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	//�������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr) {
		MessageBox::Show("�� ��� ������ �������!", "��������!");
		return;
	}

	//���������� ������
	String^ ��� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ searchWord = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ sites = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//��������� ������ � ��
	dbConnection->Open(); //��������� ����������
	String^ querty = "INSERT INTO [table] VALUES ("+ ��� +", '" + searchWord + "', '" + sites + "')"; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(querty, dbConnection); //�������

	//��������� ������
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("������ ���������� �������!", "������!");
	else
		MessageBox::Show("������ ���������!", "������!");

	//��������� ���������� � ��
	dbConnection->Close();

	return System::Void();
}

System::Void Lab3::WinForm::Button_update(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������ ������ ��� ����������
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ������ ��� ����������", "��������!");
		return;
	}

	//����� ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	//�������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr) {
		MessageBox::Show("�� ��� ������ �������!", "��������!");
		return;
	}

	//���������� ������
	String^ ��� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ searchWord = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ sites = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//��������� ������ � ��
	dbConnection->Open(); //��������� ����������
	String^ querty = "UPDATE [table] SET searchWord='" + searchWord + "', sites='" + sites + "' WHERE ���=" + ��� + ""; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(querty, dbConnection); //�������

	//��������� ������
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("������ ���������� �������!", "������!");
	else
		MessageBox::Show("������ ��������!", "������!");

	//��������� ���������� � ��
	dbConnection->Close();

	return System::Void();
}

System::Void Lab3::WinForm::Button_delete(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������ ������ ��� ����������
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ������ ��� ����������", "��������!");
		return;
	}

	//����� ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	//�������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr) {
		MessageBox::Show("�� ��� ������ �������!", "��������!");
		return;
	}

	//���������� ������
	String^ ��� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//��������� ������ � ��
	dbConnection->Open(); //��������� ����������
	String^ querty = "DELETE FROM [table] WHERE ���=" + ��� + ""; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(querty, dbConnection); //�������

	//��������� ������
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("������ ���������� �������!", "������!");
	else {
		MessageBox::Show("������ �������!", "������!");
		dataGridView1->Rows->RemoveAt(index); //������� ������ �� �������
	}

	//��������� ���������� � ��
	dbConnection->Close();

	return System::Void();
}

System::Void Lab3::WinForm::Button_Exit(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();

	return System::Void();
}