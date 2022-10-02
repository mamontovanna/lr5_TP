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
	cout << "�������� ������" << endl;
	cout << "��� ������: " << type << endl;
	if (type == "���") {
		cout << "�������: ������: " << a << endl;
	}
	if (type == "���") {
		cout << "�������: ������� ����: " << a << endl;
	}
	if (type == "��������������") {
		cout << " �������: ����� : " << a << ", ������ : " << b << ", ������: " << c << endl;
	}
	if (type == "������������� ��������") {
		cout << "�������: ����� ��������� : " << a << ", ������ ���������: " << b << ", ������: " << c << endl;
	}
	cout << "�����: " << V << endl;
	cout << pict << endl;
	cout << "-------------------------------" << endl;
}
void Solid::rewrite()
{
	int f;
	cout << "-------------------------------" << endl;
	cout << "�������� ������" << endl;
	cout << "�������� �������� ��� ������:" << endl;
	cout << "1 - ���" << endl;
	cout << "2 - ���" << endl;
	cout << "3 - ��������������" << endl;
	cout << "4 - ������������� ��������" << endl;
	cin >> f;
	switch (f)
	{
	case 1:
		this->type = "���";
		cout << "������� ������ ����:" << endl;
		cin >> a;
		V = (4 * PI * pow(a, 3)) / 3;
		pict = "�������_����";
		break;
	case 2:
		type = "���";
		cout << "������� ������� ����:" << endl;
		cin >> a;
		pict = "�������_����";
		V = pow(a, 3);
		break;
	case 3:
		type = "��������������";
		cout << "������� ����� ���������������:" << endl;
		cin >> a;
		cout << "������� ������ ���������������:" << endl;
		cin >> b;
		cout << "������� ������ ���������������" << endl;
		cin >> c;
		pict = "�������_���������������";
		V = a * b * c;
		break;
	case 4:
		type = "������������� ��������";
		cout << "������� ����� ��������� ��������:" << endl;
		cin >> a;
		cout << "������� ������ ��������� ��������:" << endl;
		cin >> b;
		cout << "������� ������ ��������: " << endl;
		cin >> c;
		V = (a * b * c) / 3;
		pict = "�������_�������������_��������";
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
	if (type == "���") {
		V = (4 * PI * pow(a, 3)) / 3;
	}
	if (type == "���") {
		V = pow(a, 3);
	}
	if (type == "��������������") {
		V = a * b*c;
	}
	if (type == "������������� ��������") {
		
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
double Solid::Per()//�������� ���������/������� 
{
	if (type == "���") {
		return 2 * PI * a;
	}
	if (type == "���") {
		return 4 * a;
	}
	if (type == "��������������") {
		return 2 * (a + b);
	}
	if (type == "������������� ��������") {
		return 2 * (a + b);
	}
}