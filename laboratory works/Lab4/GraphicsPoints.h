#pragma once

#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class GraphicsPoints
{
public:
	GraphicsPoints();
	void Paint_Graphics(GroupBox^);
	void Paint_Bar_Chart(GroupBox^);
	void Paint_Buble(GroupBox^);
private:
	array<int>^ row_1;
	array<int>^ row_2;
	array<int>^ row_3;
	int coefficient;
};