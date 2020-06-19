#include "pch.h"
#include "MyForm.h"
#include "GraphicsPoints.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab4::MyForm form;
	Application::Run(% form);

	return 0;
}