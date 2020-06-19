#include "pch.h"
#include "MyClass.h"

/*
	Дано:
Перечисление ключевых слов и сайтов,
на которых встречается каждое из них

	Получить:
Набор сайтов, где встречается
(не встречается) указанное подмножество
ключевых слов
*/

using namespace System;
using namespace System::Collections;

int main(array<System::String^>^ args)
{
	MyClass ClassObj;
	ClassObj.AddNameToList("www.people-rights.ru/Alliance");
	ClassObj.AddNameToList("www.people-rights.ru/Union");
	ClassObj.AddNameToList("www.people-rights.ru/Ruts");
	ClassObj.AddNameToList("www.tea-house.ru/Dark");
	ClassObj.AddNameToList("www.tobacco.ru/Dark");
	ClassObj.AddNameToList("www.people-rights.ru/Dark");
	ClassObj.AddNameToList("www.tobacco.ru/Side");
	ClassObj.AddNameToList("www.people-rights.ru/Side");
	ClassObj.AddNameToList("www.tobacco.ru/Musthave");
	ClassObj.AddNameToList("www.tea-house.ru/Curtis");
	ClassObj.AddNameToList("www.tea-house.ru/Greenfield");
	ClassObj.AddNameToList("www.tea-house.ru/Tess");
	ClassObj.SaveToSitesWithWords("Dark");
	ClassObj.SaveToSitesWithoutWords("Dark");
	return 0;
}