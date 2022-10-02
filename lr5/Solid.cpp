#include "Lib.h"

using namespace std;

Solid::Solid() {
	a = 0;
	b = 0;
	c = 0;
	V = 0;
	pict = ' ';
	type = ' ';
	cout << "Constructor Solid without parameters was called" << endl;
}
Solid::Solid(string type) {
	cout << "Constructor Solid with parameters was called" << endl;
	this->type = type;
}
Solid::Solid(const Solid& Solid_copy)
{
	cout << " Copy Constructor Solid  was called" << endl;
	type = Solid_copy.type;
	V = Solid_copy.V;
	a = Solid_copy.a;
	b = Solid_copy.b;
	c = Solid_copy.c;
	pict = Solid_copy.pict;
}
Solid::~Solid()
{
	cout << "Destructor Solid was called" << endl;
}

void Solid::set_type(string f_type)
{
	this->type = f_type;
}
void Solid::set_a(double a)
{
	this->a = a;

}
void Solid::set_b(double b)
{
	this->b = b;
}
void Solid::set_c(double c)
{
	this->c = c;
}
void Solid::set_V(double V)
{
	this->V = V;
}
void Solid::set_pict(string pict)
{
	this->pict = pict;
}
string Solid::get_type() const
{
	return type;
}double Solid::get_V() const
{
	return V;
}
double Solid::get_a() const
{
	return a;
}
double Solid::get_b() const
{
	return b;
}

double Solid::get_c() const
{
	return 0.0;
}
string Solid::get_pict() const
{
	return pict;
}
void Solid::show()
{
	cout << "-------------------------------" << endl;
	cout << "ОБЪЕМНАЯ ФИГУРА" << endl;
	cout << "Тип фигуры: " << type << endl;
	if (type == "Шар") {
		cout << "Размеры: Радиус: " << a << endl;
	}
	if (type == "Куб") {
		cout << "Размеры: Сторона куба: " << a << endl;
	}
	if (type == "Параллелепипед") {
		cout << " Размеры: Длина : " << a << ", ширина : " << b << ", высота: " << c << endl;
	}
	if (type == "Прямоугольная пирамида") {
		cout << "Размеры: Длина основания : " << a << ", ширина основания: " << b << ", высота: " << c << endl;
	}
	cout << "Объем: " << V << endl;
	cout << pict << endl;
	cout << "-------------------------------" << endl;
}
void Solid::rewrite()
{
	int f;
	cout << "-------------------------------" << endl;
	cout << "ОБЪЕМНАЯ ФИГУРА" << endl;
	cout << "Выберете желаемый тип фигуры:" << endl;
	cout << "1 - Шар" << endl;
	cout << "2 - Куб" << endl;
	cout << "3 - Параллелепипед" << endl;
	cout << "4 - Прямоугольная пирамида" << endl;
	cin >> f;
	switch (f)
	{
	case 1:
		this->type = "Шар";
		cout << "Введите радиус Шара:" << endl;
		cin >> a;
		V = (4 * PI * pow(a, 3)) / 3;
		pict = "Рисунок_шара";
		break;
	case 2:
		type = "Куб";
		cout << "Введите сторону куба:" << endl;
		cin >> a;
		pict = "Рисунок_куба";
		V = pow(a, 3);
		break;
	case 3:
		type = "Параллелепипед";
		cout << "Введите длину параллелепипеда:" << endl;
		cin >> a;
		cout << "Введите ширину параллелепипеда:" << endl;
		cin >> b;
		cout << "Введите высоту параллелепипеда" << endl;
		cin >> c;
		pict = "Рисунок_параллелепипеда";
		V = a * b * c;
		break;
	case 4:
		type = "Прямоугольная пирамида";
		cout << "Введите длину основания пирамиды:" << endl;
		cin >> a;
		cout << "Введите ширину основания пирамиды:" << endl;
		cin >> b;
		cout << "Введите высоту пирамиды: " << endl;
		cin >> c;
		V = (a * b * c) / 3;
		pict = "Рисунок_прямоугольной_пирамиды";
		break;
		/*default:
			break;*/
	}
}
void Solid::redact(int item1, int item2, int item3)
{
	this->a = item1;
	this->b = item2;
	this->c = item3;
	if (type == "Шар") {
		V = (4 * PI * pow(a, 3)) / 3;
	}
	if (type == "Куб") {
		V = pow(a, 3);
	}
	if (type == "Параллелепипед") {
		V = a * b*c;
	}
	if (type == "Прямоугольная пирамида") {
		
		V= (a * b * c) / 3;
	}
}
void Solid::saving()
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
		fout << 2 << endl << type << endl << a << endl << b << endl << c << endl << V << endl << pict << endl;
		fout.close();
	}
}
double Solid::Per()//периметр основания/сечения 
{
	if (type == "Шар") {
		return 2 * PI * a;
	}
	if (type == "Куб") {
		return 4 * a;
	}
	if (type == "Параллелепипед") {
		return 2 * (a + b);
	}
	if (type == "Прямоугольная пирамида") {
		return 2 * (a + b);
	}
}