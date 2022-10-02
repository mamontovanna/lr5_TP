#include "Lib.h"
using namespace std;
Keeper::Keeper()
{
	size = 0;
	head = nullptr;
}
Keeper::Keeper(int size) :head(nullptr)
{
	this->size = size;
}
Keeper::~Keeper() {
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Figure();
			delete(buffer);
		}
		head->data->~Figure();
		delete(head);
	}
}
int Keeper::get_size()
{
	return size;
}
Figure* Keeper::operator[] (const int index)
{
	if ((index >= size) || (index < 0))
	{
		throw "Incorrect index!";
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < size-index-1 ; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->data);
	}
}
void Keeper::insert(Figure* n_data)
{
	Elem* tmp;
	tmp = new Elem;
	if (size == 0) {
		tmp->data = n_data;
		tmp->next = 0;
		++size;
	}
	else {
		tmp->data = n_data;
		tmp->next =head;
		++size;
	}
	head = tmp;
}
void Keeper::remove(int index)
{
	if (size == 0) {
		throw "Фигур нет! Удалять нечего!";
	}
	int cnt = 0;
	while (cnt < index-1)
	{
		head = head->next;
		cnt++;
	}
	Elem* prev = head;
	prev->next->data->~Figure();
	prev->next->next;
	delete(prev->next);
	--size;
}
void Keeper::save()
{
	ofstream fout;
	string initfile = "data.txt";
	fout.open(initfile, ios_base::app);
	if (!fout)
	{
		throw "Ошибка открытия файла!";
		system("pause");
		exit(1);
	}
	else
	{
		fout << size << endl;
		fout.close();
	}
	Elem* buf = head;
	for (int i = 0; i < size; i++) {
		buf->data->saving();
		buf = buf->next;
	}
}
void Keeper::load()
{
	setlocale(LC_ALL, "Russian");
	if (size != 0)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Figure();
			delete(head);
		}
		head->data->~Figure();
		delete(head);
	}
	ifstream fin;
	string initfile = "data.txt";
	Figure* figures;
	int fsize;// для считывания количества объектов в файле
	int num_type;//1- плоская, 2- объемная фигуры
	string ftype, fpict;
	double a1, b1, c1, d1;//размеры, включая площадь/объем
	fin.open(initfile);
	if (!fin) {
		throw "Ошибка открытия файла!";
		system("pause");
		exit(1);
	}
	fin >> fsize;
	
	for (int i = 0; i < fsize; i++) {
		fin >> num_type;
		//fin.ignore(32767, '\n');
		if (num_type == 1) {
			
			fin>> ftype >> a1 >> b1 >> c1 >> d1 >> fpict;
			Flat* flat;
			flat = new Flat;
			flat->set_type(ftype);
			flat->set_a(a1);
			flat->set_b(b1);
			flat->set_c(c1);
			flat->set_S(d1);
			flat->set_pict(fpict);
			figures = flat;
			insert(figures);
		}
		if (num_type == 2) {
			fin >> ftype >> a1 >> b1 >> c1 >> d1 >> fpict;
			Solid* solid;
			solid = new Solid;
			solid->set_type(ftype);
			solid->set_a(a1);
			solid->set_b(b1);
			solid->set_c(c1);
			solid->set_V(d1);
			solid->set_pict(fpict);
			figures = solid;
			insert(figures);
		}
		fin.ignore(32767, '\n');
	}
}