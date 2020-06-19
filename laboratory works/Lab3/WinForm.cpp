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

System::Void Lab3::WinForm::СправкаToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Программа для работы с БД Гамаюновой К. Д., КТбо1-9. \r\n\nСписок действий: \r\n\"Загрузить данные\" - загружает данные из БД в таблицу. \r\n\"Добавить\" - добавляет строку в БД. \r\n\"Изменить\"  - изменяет строку данных в БД. \r\n\"Удалить\" - удаляет строку данных из БД. \r\n\"Выйти\" - закрывает программу.", "О программе");

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
		MessageBox::Show("Ошибка считывания данных!","Ошибка!");
	}
	else
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["Код"], dbReader["searchWord"], dbReader["sites"]);
		}
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void Lab3::WinForm::Button_add(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор нужной строки для добавления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите строку для добавления", "Внимание!");
		return;
	}

	//Узнаём индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	//Считывание данных
	String^ Код = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ searchWord = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ sites = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполняем запрос к БД
	dbConnection->Open(); //открываем соединение
	String^ querty = "INSERT INTO [table] VALUES ("+ Код +", '" + searchWord + "', '" + sites + "')"; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(querty, dbConnection); //команда

	//Выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные добавлены!", "Готово!");

	//Закрываем соединение с БД
	dbConnection->Close();

	return System::Void();
}

System::Void Lab3::WinForm::Button_update(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор нужной строки для добавления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите строку для добавления", "Внимание!");
		return;
	}

	//Узнаём индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	//Считывание данных
	String^ Код = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ searchWord = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ sites = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполняем запрос к БД
	dbConnection->Open(); //открываем соединение
	String^ querty = "UPDATE [table] SET searchWord='" + searchWord + "', sites='" + sites + "' WHERE Код=" + Код + ""; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(querty, dbConnection); //команда

	//Выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные изменены!", "Готово!");

	//Закрываем соединение с БД
	dbConnection->Close();

	return System::Void();
}

System::Void Lab3::WinForm::Button_delete(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор нужной строки для добавления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите строку для добавления", "Внимание!");
		return;
	}

	//Узнаём индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	//Считывание данных
	String^ Код = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполняем запрос к БД
	dbConnection->Open(); //открываем соединение
	String^ querty = "DELETE FROM [table] WHERE Код=" + Код + ""; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(querty, dbConnection); //команда

	//Выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else {
		MessageBox::Show("Данные удалены!", "Готово!");
		dataGridView1->Rows->RemoveAt(index); //Удаляем строку из таблицы
	}

	//Закрываем соединение с БД
	dbConnection->Close();

	return System::Void();
}

System::Void Lab3::WinForm::Button_Exit(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();

	return System::Void();
}