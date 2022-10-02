#include "Lib.h"
using namespace std;

void Menu::main_menu()
{
	while (exit == 1) {
		switch (show_options())
		{
		case 1:
			show_all_figures();
			break;
		case 2:
			change_data();
			break;
		case 3:
			add_new();
			break;
		case 4:
			save_to_file();
			break;
		case 5:
			load_from_file();
			break;
		case 6:
			delete_figure();
			break;
		case 7:
			find_per();
			break;
		case 8:
			exit_from_programm();
			break;
		}
	}
}
int Menu::show_options()
{
	int c1;
	cout << " �������� ��������:" << endl;
	cout << "1 - ����� ���� �����" << endl;
	cout << "2 - ������������� ������" << endl;
	cout << "3 - �������� ������" << endl;
	cout << "4 - ��������� � ����" << endl;
	cout << "5 - �������� �� �����" << endl;
	cout << "6 - ������� ������" << endl;
	cout << "7 - ����� �������� ������ ��� �������� �������" << endl;
	cout << "8 - �����" << endl;
	cin >> c1;
	return c1;
}

void Menu::show_all_figures()
{
	try
	{
		if (list.get_size() == 0) {
			throw "������ ����! �������� ������!";
		}
		for (int i = 0; i < list.get_size(); i++) {
			list[i]->show();
		}
	}
	catch (const char* er)
	{
		cout << er << endl;
		cout << "���������� ����������!" << endl;
	}
	
}

void Menu::change_data()
{
	int c2;
	try
	{
		cout << "����� ������ ������ ��������?" << endl;
		cout << "������� ����� ������ �� 1 �� " << list.get_size() << endl;
		cin >> c2;
		if (c2<1 || c2>list.get_size()) {
			throw "������������ �����!";
		}
		list[c2 - 1]->show();
		cout << "����� �������� ���������� �������������?" << endl;
		int par;
		cout << "1 - ���" << endl;
		cout << "2 - �������" << endl;
		cin >> par;
		switch (par) {
		case 1:
			cout << "��� ����� ���� ������ ���������� �������� �� �������" << endl;
			list[c2 - 1]->rewrite();
			break;
		case 2:
			double a1, a2, a3;
			cout << "������� ��� ����� �������." << endl;
			cout << "���� � ������ (�������� ����) ���� ������ 1 ������ (������), ������� ������, � ��������� ��������� ������� �����" << endl;
			cin >> a1 >> a2 >> a3;
			list[c2 - 1]->redact(a1, a2, a3);
			break;
		}
		cout << "������ ��������!" << endl;

	}
	catch (const char* err)
	{
		cout << err << endl;
		cout << "���������� ����������!" << endl;
	}
	
}
void Menu::add_new()
{
	int c3;
	cout << "����� ������ ���������� ��������?" << endl;
	cout << "1 - �������" << endl;
	cout << "2 - ��������" << endl;
	cin >> c3;
	switch (c3) {
	case 1:
		Flat * flat;
		flat = new Flat;
		figures = flat;
		flat->rewrite();
		list.insert(figures);
		break;
	case 2:
		Solid * solid;
		solid = new Solid;
		figures = solid;
		solid->rewrite();
		list.insert(figures);
		break;
	default:
		break;
	}
	cout << "����� ������ ���� ���������!" << endl;
}
void Menu::save_to_file()
{
	try
	{
		if (list.get_size() == 0) {
			throw "������ ����! ��������� ������!";
		}
		list.save();
		cout << "������ ��������� � ���� data.txt" << endl;
	}
	catch (...)
	{
		cout << "������� ����������!" << endl;
		cout << "���������� ����������!" << endl;
	}
	
}
void Menu::load_from_file()
{
	list.load();
	cout << "������ ��������� �� �����!" << endl;
}
void Menu::delete_figure()
{
	int c4;
	try
	{
		if (list.get_size() == 0) {
			throw "������ ����!";
		}
	}
	catch (...)
	{
		cout << "������� ����������!" << endl;
		cout << "���������� ����������!" << endl;
	}

	cout << "����� ������ �� ������ �������?" << endl;
	cout << "������� ����� �� 1 �� " << list.get_size() << endl;
	/*for (int i = 0; i < list.get_size(); i++) {
		list[i]->show();
	}*/
	try
	{
		cin >> c4;
		if (c4<1 || c4>list.get_size())
		{
			throw"������� ������������ �����!";
		}
		list.remove(list.get_size()-c4);
		cout << "��������� ������ �������" << endl;
		
	}
	catch (...)
	{
		cout << "������� ����������!" << endl;
		cout << "���������� ����������!" << endl;
	}
	
}
void Menu::find_per()
{
	int p1;
	try
	{
		for (int i = 0; i < list.get_size(); i++) {
			list[i]->show();
		}
		cout << "������� ����� ������, �������� ��� �������� ���������/������� ������� ���������� �����" << endl;
		cin >> p1;
		if (p1<1 || p1>list.get_size()) {
			throw "������� ������������ �����!";
		}
		cout << "��������: " << list[p1 - 1]->Per() << endl;

	}
	catch (...)
	{
		cout << "������� ����������!" << endl;
		cout << "���������� ����������!" << endl;
	}
	
}

void Menu::exit_from_programm()
{
	exit = 0;
}