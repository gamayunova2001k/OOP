#include "pch.h"
#include "GraphicsPoints.h"

GraphicsPoints::GraphicsPoints()
{
	row_1 = gcnew array<int>(10) { 5, 13, 15, 10, 7, 0, 6, 15, 5, 10 };
	row_2 = gcnew array<int>(10) { 2, 10, 21, 8, 9, 3, 1, 17, 4, 7 };
	coefficient = 10;

	row_3 = gcnew array<int>(10) { 4, 2, 5, 8, 9, 3, 1, 2, 4, 7 };
}

void GraphicsPoints::Paint_Bar_Chart(GroupBox^ groupBox)
{
	Graphics^ S = groupBox->CreateGraphics();
	S->Clear(Color::White);
	Pen^ pen = gcnew Pen(Color::Black);
	System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
	StringFormat^ format = gcnew StringFormat(StringFormatFlags::NoClip);
	format->Alignment = StringAlignment::Center;
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
	Brush^ brush1 = gcnew SolidBrush(Color::Gold);
	Brush^ brush2 = gcnew SolidBrush(Color::DodgerBlue);
	double Height_GroupBox = groupBox->Height;
	double Width_GroupBox = groupBox->Width;
	//Горизонтальные линии диаграммы
	for (int i = 0, k = Height_GroupBox - 50; i < 6; i++, k = k - 50) {
		S->DrawLine(pen, 30, k, Width_GroupBox - 15, k);
	}
	//Название диаграммы
	System::Drawing::Font^ drawNameFont = gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold);
	String^ NameString = "Гистрограмма";
	PointF NamePoint = PointF(Width_GroupBox / 2, Height_GroupBox - (Height_GroupBox - 15));
	S->DrawString(NameString, drawNameFont, drawBrush, NamePoint, format);
	//Горизонтальная линия значений
	for (int i = 1, k = Width_GroupBox / 25 + 26; i < 11; i++, k = (k + Width_GroupBox / row_1->Length) - 4)
	{
		String^ drawstring = Convert::ToString(i);
		PointF drawPoint = PointF(k, Height_GroupBox - 45);
		S->DrawString(drawstring, drawFont, drawBrush, drawPoint);
	}
	//Вертикальная линия значений
	for (int i = 0, k = Height_GroupBox - 57; i < 26; i = i + 5, k = k - 50)
	{
		String^ drawstring = Convert::ToString(i);
		PointF drawPoint = PointF(5, k);
		S->DrawString(drawstring, drawFont, drawBrush, drawPoint);
	}
	//Легенда диаграммы
	String^ legendString1 = "Ряд1";
	PointF legendPoint1 = PointF((Width_GroupBox + 60) / 2 - 45, Height_GroupBox - 20);
	S->DrawString(legendString1, drawFont, drawBrush, legendPoint1);
	S->FillRectangle(brush1, ((Width_GroupBox + 60) / 2 - 60), (Height_GroupBox - 20), 10, 10);
	S->DrawRectangle(pen, ((Width_GroupBox + 60) / 2 - 60), (Height_GroupBox - 20), 10, 10);
	String^ legendString2 = "Ряд2";
	PointF legendPoint2 = PointF((Width_GroupBox + 60) / 2 + 15, Height_GroupBox - 20);
	S->DrawString(legendString2, drawFont, drawBrush, legendPoint2);
	S->FillRectangle(brush2, ((Width_GroupBox + 60) / 2), (Height_GroupBox - 20), 10, 10);
	S->DrawRectangle(pen, ((Width_GroupBox + 60) / 2), (Height_GroupBox - 20), 10, 10);
	//Отрисовка данных для ряда 1
	array<Rectangle>^ Rectangles_row1 = gcnew array<Rectangle>(row_1->Length);
	for (int i = 0, coordinate_x = 30; i < row_1->Length; i++, coordinate_x = coordinate_x + (Width_GroupBox - 35) / row_1->Length)
	{
		double x = (Height_GroupBox - 50 - 10 * row_1[i]);
		double y = Height_GroupBox - 50 - (Height_GroupBox - 50 - (10 * row_1[i]));
		Rectangles_row1[i] = Rectangle(coordinate_x, x, Width_GroupBox / 25, y);
	}
	S->FillRectangles(brush1, Rectangles_row1);
	S->DrawRectangles(pen, Rectangles_row1);
	//Отрисовка данных для ряда 2
	array<Rectangle>^ Rectangles_row2 = gcnew array<Rectangle>(row_2->Length);
	for (int i = 0, coordinate_x = 30 + Width_GroupBox / 25; i < row_2->Length; i++, coordinate_x = coordinate_x + (Width_GroupBox - 35) / row_2->Length)
	{
		double x = (Height_GroupBox - 50 - 10 * row_2[i]);
		double y = Height_GroupBox - 50 - (Height_GroupBox - 50 - (10 * row_2[i]));
		Rectangles_row2[i] = Rectangle(coordinate_x, x, Width_GroupBox / 25, y);
	}
	S->FillRectangles(brush2, Rectangles_row2);
	S->DrawRectangles(pen, Rectangles_row2);
	//Подпись значений ряда 1
	array<Point>^ coordinate_graphics_row1 = gcnew array<Point>(row_1->Length);
	for (int i = 0, k = 33; i < 10; i++, k = k + (Width_GroupBox - 33) / row_1->Length)
	{
		coordinate_graphics_row1[i] = Point(k, Height_GroupBox - 50 - 10 * row_1[i] - 15);
		String^ drawstring = Convert::ToString(row_1[i]);
		S->DrawString(drawstring, drawFont, drawBrush, coordinate_graphics_row1[i]);
	}
	//Подпись значений ряда 2
	array<Point>^ coordinate_graphics_row2 = gcnew array<Point>(row_2->Length);
	for (int i = 0, k = 33 + Width_GroupBox / 25; i < 10; i++, k = k + (Width_GroupBox - 33) / row_2->Length)
	{
		coordinate_graphics_row2[i] = Point(k, Height_GroupBox - 50 - 10 * row_2[i] - 15);
		String^ drawstring = Convert::ToString(row_2[i]);
		S->DrawString(drawstring, drawFont, drawBrush, coordinate_graphics_row2[i]);
	}
}

void GraphicsPoints::Paint_Graphics(GroupBox^ groupBox)
{
	Graphics^ S = groupBox->CreateGraphics();
	S->Clear(Color::White);
	Pen^ pen_line = gcnew Pen(Color::Black);
	Pen^ pen_row1 = gcnew Pen(Color::DarkMagenta, 4.0f);
	Pen^ pen_row2 = gcnew Pen(Color::DarkCyan, 4.0f);
	System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
	StringFormat^ format = gcnew StringFormat(StringFormatFlags::NoClip);
	format->Alignment = StringAlignment::Center;
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
	double Height_GroupBox = groupBox->Height;
	double Width_GroupBox = groupBox->Width;
	//Горизонтальные линии диаграммы
	for (int i = 0, k = Height_GroupBox - 50; i < 6; i++, k = k - 50) {
		S->DrawLine(pen_line, 30, k, Width_GroupBox - 15, k);
	}
	//Название диаграммы
	System::Drawing::Font^ drawNameFont = gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold);
	String^ NameString = "График";
	PointF NamePoint = PointF(Width_GroupBox / 2, Height_GroupBox - (Height_GroupBox - 15));
	S->DrawString(NameString, drawNameFont, drawBrush, NamePoint, format);
	//Горизонтальная линия значений
	for (int i = 1, k = 25; i < 11; i++, k = k + Width_GroupBox / row_1->Length)
	{
		String^ drawstring = Convert::ToString(i);
		PointF drawPoint = PointF(k, Height_GroupBox - 45);
		S->DrawString(drawstring, drawFont, drawBrush, drawPoint);
	}
	//Вертикальная линия значений
	for (int i = 0, k = Height_GroupBox - 57; i < 26; i = i + 5, k = k - 50)
	{
		String^ drawstring = Convert::ToString(i);
		PointF drawPoint = PointF(5, k);
		S->DrawString(drawstring, drawFont, drawBrush, drawPoint);
	}
	//Леганда диаграммы
	String^ legendString1 = "Ряд1";
	PointF legendPoint1 = PointF((Width_GroupBox + 60) / 2 - 45, Height_GroupBox - 20);
	PointF legendPoint12 = PointF(Width_GroupBox / 2 - 45, Height_GroupBox - 20);
	S->DrawString(legendString1, drawFont, drawBrush, legendPoint1);
	S->DrawLine(pen_row1, legendPoint1, legendPoint12);
	String^ legendString2 = "Ряд2";
	PointF legendPoint2 = PointF((Width_GroupBox + 60) / 2, Height_GroupBox - 20);
	PointF legendPoint22 = PointF((Width_GroupBox + 60) / 2 + 30, Height_GroupBox - 20);
	S->DrawString(legendString2, drawFont, drawBrush, legendPoint22);
	S->DrawLine(pen_row2, legendPoint2, legendPoint22);
	//Отрисовка данных для ряда 1
	array<Point>^ Graphic_row1 = gcnew array<Point>(row_1->Length);
	for (int i = 0, k = 30; i < row_1->Length; i++, k = k + Width_GroupBox / row_1->Length)
	{
		Graphic_row1[i] = Point(k, (Height_GroupBox - 50) - row_1[i] * coefficient);
	}
	S->DrawLines(pen_row1, Graphic_row1);
	//Отрисовка данных для ряда 2
	array<Point>^ Graphic_row2 = gcnew array<Point>(row_2->Length);
	for (int i = 0, k = 30; i < row_2->Length; i++, k = k + Width_GroupBox / row_2->Length)
	{
		Graphic_row2[i] = Point(k, (Height_GroupBox - 50) - row_2[i] * coefficient);
	}
	S->DrawLines(pen_row2, Graphic_row2);
	//Подпись значений ряда 1
	array<Point>^ coordinate_row1 = gcnew array<Point>(row_1->Length);
	for (int i = 0, k = 33; i < row_1->Length; i++, k = k + Width_GroupBox / row_1->Length)
	{
		coordinate_row1[i] = Point(k, (Height_GroupBox - 55) - row_1[i] * coefficient);
		String^ drawstring = Convert::ToString(row_1[i]);
		S->DrawString(drawstring, drawFont, drawBrush, coordinate_row1[i]);
	}
	//Подпись значений ряда 2
	array<Point>^ coordinate_row2 = gcnew array<Point>(row_2->Length);
	for (int i = 0, k = 33; i < row_2->Length; i++, k = k + Width_GroupBox / row_2->Length)
	{
		coordinate_row2[i] = Point(k, (Height_GroupBox - 55) - row_2[i] * coefficient);
		String^ drawstring = Convert::ToString(row_2[i]);
		S->DrawString(drawstring, drawFont, drawBrush, coordinate_row2[i]);
	}
}

void GraphicsPoints::Paint_Buble(GroupBox^ groupBox) {
	Graphics^ S = groupBox->CreateGraphics();
	S->Clear(Color::White);
	Pen^ pen = gcnew Pen(Color::Black);
	System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
	StringFormat^ format = gcnew StringFormat(StringFormatFlags::NoClip);
	format->Alignment = StringAlignment::Center;
	StringFormat^ format2 = gcnew StringFormat(StringFormatFlags::NoClip);
	format2->Alignment = StringAlignment::Far;
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
	Brush^ brush1 = gcnew SolidBrush(Color::DeepPink);
	double Height_GroupBox = groupBox->Height;
	double Width_GroupBox = groupBox->Width;
	double x = 0;
	double y = 0;
	//Горизонтальные линии диаграммы
	for (int i = 0, k = Height_GroupBox - 30; i < 14; i++, k = k - 20) {
		S->DrawLine(pen, 30, k, Width_GroupBox - 80, k);
	}
	//Вертикальная линия диаграммы
	S->DrawLine(pen, (30 + (Width_GroupBox - 110) / 4), (Height_GroupBox - 30), (30 + (Width_GroupBox - 110) / 4), 77);
	//Название диаграммы
	System::Drawing::Font^ drawNameFont = gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold);
	String^ NameString = "Пузырьковая диаграмма";
	PointF NamePoint = PointF(Width_GroupBox / 2, Height_GroupBox - (Height_GroupBox - 15));
	S->DrawString(NameString, drawNameFont, drawBrush, NamePoint, format);
	//Подпись осей
	String^ stringY = "Y";
	PointF PointY = PointF(10, Height_GroupBox / 2);
	S->DrawString(stringY, drawFont, drawBrush, PointY);
	String^ stringX = "X";
	PointF PointX = PointF(Width_GroupBox / 2 + 2, Height_GroupBox - 20);
	S->DrawString(stringX, drawFont, drawBrush, PointX);
	//Горизонтальная линия значений
	for (int i = -5, k = 30; i < 16; i = i + 5, k = (k + (Width_GroupBox - 110) / 4))
	{
		String^ drawstring = Convert::ToString(i);
		PointF drawPoint = PointF(k, Height_GroupBox - 50);
		S->DrawString(drawstring, drawFont, drawBrush, drawPoint, format);
	}
	//Вертикальная линия значений
	for (int i = -4, k = Height_GroupBox - 37; i < 23; i = i + 2, k = k - 20)
	{
		String^ drawstring = Convert::ToString(i);
		PointF drawPoint = PointF(100, k);
		S->DrawString(drawstring, drawFont, drawBrush, drawPoint, format2);
	}
	//Леганда диаграммы
	String^ legendString1 = "Ряд1";
	PointF legendPoint1 = PointF(Width_GroupBox - 55, Height_GroupBox / 2);
	S->DrawString(legendString1, drawFont, drawBrush, legendPoint1);
	S->FillEllipse(brush1, (Width_GroupBox - 70), (Height_GroupBox / 2), 10, 10);
	S->DrawEllipse(pen, (Width_GroupBox - 70), (Height_GroupBox / 2), 10, 10);
	//Отрисовка данных диаграммы
	for (int i = 0; i < coefficient; i++)
	{
		x = (30 + (Width_GroupBox - 110) / 4) + row_1[i] * ((Width_GroupBox - 110) / 20);
		y = (Height_GroupBox - 70) - row_2[i] * 10;
		S->FillEllipse(brush1, x - row_3[i] * 5, y - row_3[i] * 5, row_3[i] * 10, row_3[i] * 10);
		S->DrawEllipse(pen, x - row_3[i] * 5, y - row_3[i] * 5, row_3[i] * 10, row_3[i] * 10);
	}
}