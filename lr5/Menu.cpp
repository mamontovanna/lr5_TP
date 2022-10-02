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
	cout << " Выберете действие:" << endl;
	cout << "1 - Вывод всех фигур" << endl;
	cout << "2 - Редактировать данные" << endl;
	cout << "3 - Добавить фигуру" << endl;
	cout << "4 - Сохранить в файл" << endl;
	cout << "5 - Выгрузка из файла" << endl;
	cout << "6 - Удалить фигуру" << endl;
	cout << "7 - Найти периметр фигуры или периметр сечения" << endl;
	cout << "8 - Выход" << endl;
	cin >> c1;
	return c1;
}

void Menu::show_all_figures()
{
	try
	{
		if (list.get_size() == 0) {
			throw "Список пуст! Выводить нечего!";
		}
		for (int i = 0; i < list.get_size(); i++) {
			list[i]->show();
		}
	}
	catch (const char* er)
	{
		cout << er << endl;
		cout << "Исключение обработано!" << endl;
	}
	
}

void Menu::change_data()
{
	int c2;
	try
	{
		cout << "Какую фигуру хотите изменить?" << endl;
		cout << "Введите номер фигуры от 1 до " << list.get_size() << endl;
		cin >> c2;
		if (c2<1 || c2>list.get_size()) {
			throw "Некорректный номер!";
		}
		list[c2 - 1]->show();
		cout << "Какой параметр необходимо редактировать?" << endl;
		int par;
		cout << "1 - Тип" << endl;
		cout << "2 - Размеры" << endl;
		cin >> par;
		switch (par) {
		case 1:
			cout << "При смене типа фигуры необходимо изменить ее размеры" << endl;
			list[c2 - 1]->rewrite();
			break;
		case 2:
			double a1, a2, a3;
			cout << "Введите три новых размера." << endl;
			cout << "Если у фигуры (например круг) есть только 1 размер (радиус), введите радиус, а остальные параметры задайте нулем" << endl;
			cin >> a1 >> a2 >> a3;
			list[c2 - 1]->redact(a1, a2, a3);
			break;
		}
		cout << "Данные изменены!" << endl;

	}
	catch (const char* err)
	{
		cout << err << endl;
		cout << "Исключение обработано!" << endl;
	}
	
}
void Menu::add_new()
{
	int c3;
	cout << "Какую фигуру необходимо добавить?" << endl;
	cout << "1 - Плоская" << endl;
	cout << "2 - Объемная" << endl;
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
	cout << "Новая фигура была добавлена!" << endl;
}
void Menu::save_to_file()
{
	try
	{
		if (list.get_size() == 0) {
			throw "Список пуст! Сохранять нечего!";
		}
		list.save();
		cout << "Данные сохранены в файл data.txt" << endl;
	}
	catch (...)
	{
		cout << "Вызвано исключение!" << endl;
		cout << "Исключение обработано!" << endl;
	}
	
}
void Menu::load_from_file()
{
	list.load();
	cout << "Данные извлечены из файла!" << endl;
}
void Menu::delete_figure()
{
	int c4;
	try
	{
		if (list.get_size() == 0) {
			throw "Список пуст!";
		}
	}
	catch (...)
	{
		cout << "Вызвано исключение!" << endl;
		cout << "Исключение обработано!" << endl;
	}

	cout << "Какую фигуру вы хотите удалить?" << endl;
	cout << "Введите число от 1 до " << list.get_size() << endl;
	/*for (int i = 0; i < list.get_size(); i++) {
		list[i]->show();
	}*/
	try
	{
		cin >> c4;
		if (c4<1 || c4>list.get_size())
		{
			throw"Введено некорректное число!";
		}
		list.remove(list.get_size()-c4);
		cout << "Выбранная фигура удалена" << endl;
		
	}
	catch (...)
	{
		cout << "Вызвано исключение!" << endl;
		cout << "Исключение обработано!" << endl;
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
		cout << "Введите номер фигуры, периметр или периметр основания/сечения которой необходимо найти" << endl;
		cin >> p1;
		if (p1<1 || p1>list.get_size()) {
			throw "Введено некорректное число!";
		}
		cout << "Периметр: " << list[p1 - 1]->Per() << endl;

	}
	catch (...)
	{
		cout << "Вызвано исключение!" << endl;
		cout << "Исключение обработано!" << endl;
	}
	
}

void Menu::exit_from_programm()
{
	exit = 0;
}