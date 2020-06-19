#include "pch.h"
#include "Windows.h"
#include "MyClass.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;

[System::STAThreadAttribute]

int main(array<System::String^>^ args)
{
	System::Windows::Forms::Application::Run(gcnew Lab2::MyForm);

	return 0;
}