#pragma once

using namespace System;
using namespace System::Collections;

ref class MyClass
{
public:
	//конструктор класса
	MyClass(void);
	//добавить строку в список
	void AddNameToList(String^);
	//удалить строку из список
	void DelNameFromList(String^);
	//установить имя файла для сохранения результатов поиска
	void SetTextFileName(String^);
	//получить список сайтов с заданным словом
	ArrayList^ GetSitesWithWords(String^);
	//получить список сайтов без заданного слова
	ArrayList^ GetSitesWithoutWords(String^);
	//сохранить список сайтов с заданным словом
	void SaveToSitesWithWords(String^);
	//сохранить список сайтов без заданного слова
	void SaveToSitesWithoutWords(String^);
private:
	String^ TextFileName1;
	String^ TextFileName2;
	ArrayList^ aNames;
};