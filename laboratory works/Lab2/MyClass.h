#pragma once

using namespace System;
using namespace System::Collections;

ref class MyClass
{
public:
	//����������� ������
	MyClass(void);
	//�������� ������ � ������
	void AddNameToList(String^);
	//������� ������ �� ������
	void DelNameFromList(String^);
	//���������� ��� ����� ��� ���������� ����������� ������
	void SetTextFileName(String^);
	//�������� ������ ������ � �������� ������
	ArrayList^ GetSitesWithWords(String^);
	//�������� ������ ������ ��� ��������� �����
	ArrayList^ GetSitesWithoutWords(String^);
	//��������� ������ ������ � �������� ������
	void SaveToSitesWithWords(String^);
	//��������� ������ ������ ��� ��������� �����
	void SaveToSitesWithoutWords(String^);
private:
	String^ TextFileName1;
	String^ TextFileName2;
	ArrayList^ aNames;
};