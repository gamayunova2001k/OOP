#include "pch.h"
#include "Windows.h"
#include "MyClass.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;

MyClass::MyClass(void)
{
	TextFileName1 = gcnew String("FileIncluded.txt");
	TextFileName2 = gcnew String("FileNotIncluded.txt");
	aNames = gcnew ArrayList();
}

ArrayList^ MyClass::GetSitesWithWords(String^ Words)
{
	ArrayList^ aNameList = gcnew ArrayList();
	for (int i = 0; i < aNames->Count; i++) {
		String^ e = (String^)aNames[i];
		if (e->IndexOf(Words) > -1) {
			aNameList->Add(e);
		}
	}
	return(aNameList);
}

ArrayList^ MyClass::GetSitesWithoutWords(String^ Words)
{
	ArrayList^ aNameList = gcnew ArrayList();
	for (int i = 0; i < aNames->Count; i++) {
		String^ e = (String^)aNames[i];
		if (e->IndexOf(Words) == -1) {
			aNameList->Add(e);
		}
	}
	return(aNameList);
}

void MyClass::SetTextFileName(String^ NewName)
{
	TextFileName1 = NewName;
	TextFileName2 = NewName;
}

void MyClass::SaveToSitesWithWords(String^ Words)
{
	ArrayList^ aNameList = gcnew ArrayList();
	aNameList = GetSitesWithWords(Words);
	System::Console::WriteLine("Sites that include this word: \n");
	for (int i = 0; i < aNameList->Count; i++) {
		System::Console::WriteLine((String^)aNameList[i]);
	}
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(this->TextFileName1);
	for (int i = 0; i < aNameList->Count; i++) {
		sw->WriteLine((String^)aNameList[i]);
	}
	sw->Close();
}

void MyClass::SaveToSitesWithoutWords(String^ Words)
{
	ArrayList^ aNameList = gcnew ArrayList();
	aNameList = GetSitesWithoutWords(Words);
	System::Console::WriteLine("\nSites that not include this word: \n");
	for (int i = 0; i < aNameList->Count; i++) {
		System::Console::WriteLine((String^)aNameList[i]);
	}
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(this->TextFileName2);
	for (int i = 0; i < aNameList->Count; i++) {
		sw->WriteLine((String^)aNameList[i]);
	}
	sw->Close();
}

void MyClass::AddNameToList(String^ Name)
{
	aNames->Add(Name);
}

void MyClass::DelNameFromList(String^ Name)
{
	aNames->Remove(Name);
}