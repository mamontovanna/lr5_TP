#include "Flat.h"
#include "Figure.h"
#include<iostream>
#include<fstream>
#include<cmath>
#include "Lib.h"
#define PI 3.14
using namespace std;
Flat::Flat()
{
	a = 0;
	b = 0;
	c = 0;
	S = 0;
	pict = ' ';
	type = ' ';
	cout << "Constructor Flat without parameters was called" << endl;

}
Flat::Flat(string type)
{
	cout << "Constructor Flat with parameters was called" << endl;
	this->type = type;
}
Flat::Flat(const Flat& Flat_copy)
{
	cout << " Copy Constructor Flat  was called" << endl;
	type = Flat_copy.type;
	S = Flat_copy.S;
	a = Flat_copy.a;
	b = Flat_copy.b;
	c = Flat_copy.c;
	pict = Flat_copy.pict;
}
Flat::~Flat()
{
	cout << "Destructor Flat was called" << endl;
}
void Flat::set_type(string f_type)
{
	this->type = f_type;
}
void Flat::set_a(double a)
{
	this->a = a;
}
void Flat::set_b(double b)
{
	this->b = b;
}
void Flat::set_c(double c)
{
	this->c = c;
}
void Flat::set_S(double S) {
	this->S = S;
}
void Flat::set_pict(string pict)
{
	this->pict = pict;
}

string Flat::get_type() const
{
	return type;
}
double Flat::get_a() const
{
	return a;
}
double Flat::get_b() const
{
	return b;
}
double Flat::get_c() const
{
	return b;
}
double Flat::get_S() const
{
	return S;
}
string Flat::get_pict() const
{
	return pict;
}


void Flat::show()
{
	cout << "-------------------------------" << endl;
	cout << "ПЛОСКАЯ ФИГУРА" << endl;
	cout << "Тип фигуры: " << type << endl;
	if (type == "Круг") {
		cout << "Размеры: Радиус: " << a << endl;
	}
	if (type == "Квадрат") {
		cout << "Размеры: Сторона квадрата: " << a << endl;
	}
	if (type == "Прямоугольник") {
		cout << " Размеры: Длина прямоугольника: " << a << ", ширина прямоугольника: " << b << endl;
	}
	if (type == "Треугольник") {
		cout << "Размеры: Длина основания треугольника: " << a << ", длина боковой стороны (1): " << b << ", длина боковой стороны (2): " << c << endl;
	}
	cout << "Площадь: " << S << endl;
	cout << pict << endl;
	cout << "-------------------------------" << endl;
}
void Flat::saving()
{
	ofstream fout;
	string initfile = "data.txt";
	fout.open(initfile, ios_base::app);
	if (!fout)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}
	else
	{
		fout << 1 << endl << type << endl << a << endl << b << endl << c << endl << S << endl << pict << endl;
		fout.close();
	}
}
void Flat::rewrite()
{
	int f;
	cout << "-------------------------------" << endl;
	cout << "ПЛОСКАЯ ФИГУРА" << endl;
	cout << "Выберете желаемый тип фигуры:" << endl;
	cout << "1 - Круг" << endl;
	cout << "2 - Квадрат" << endl;
	cout << "3 - Прямоугольник" << endl;
	cout << "4 - Треугольник" << endl;
	cin >> f;
	switch (f)
	{
	case 1:
		this->type = "Круг";
		cout << "Введите радиус круга:" << endl;
		cin >> a;
		S = PI * pow(a, 2);
		pict = "Рисунок_круга";
		break;
	case 2:
		type = "Квадрат";
		cout << "Введите сторону квадрата:" << endl;
		cin >> a;
		pict = "Рисунок_квадрата";
		S = pow(a, 2);
		break;
	case 3:
		type = "Прямоугольник";
		cout << "Введите длину прямоугольника:" << endl;
		cin >> a;
		cout << "Введите ширину прямоугольника:" << endl;
		cin >> b;
		pict = "Рисунок_прямоугольника";
		S = a * b;
		break;
	case 4:
		type = "Треугольник";
		cout << "Введите длину основания треугольника:" << endl;
		cin >> a;
		cout << "Введите первую боковую сторону треугольника:" << endl;
		cin >> b;
		cout << "Введите вторую боковую сторону треугольника: " << endl;
		cin >> c;
		double p = (a + b + c) / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		pict = "Рисунок_треугольника";
		break;
		/*default:
			break;*/
	}
}
void Flat::redact(int item1, int item2, int item3)
{
	this->a = item1;
	this->b = item2;
	this->c = item3;
	if (type == "Круг") {
		S= PI*pow(a,2);
	}
	if (type == "Квадрат") {
		S = pow(a,2);
	}
	if (type == "Прямоугольник") {
		S = a*b;
	}
	if (type == "Треугольник") {
		double p1 = (a + b + c) / 2;
		S = S = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - c));
	}
}
double Flat::Per()
{
	if (type == "Круг") {
		return 2 * PI * a;
	}
	if (type == "Квадрат") {
		return 4 * a;
	}
	if (type == "Прямоугольник") {
		return 2 * (a + b);
	}
	if (type == "Треугольник") {
		return a + b + c;
	}
}