#pragma once
#include "Lib.h"
using namespace std;

class Keeper {
private:
	int size;
	Elem* head = nullptr;
public:
	Keeper();
	Keeper(int size);
	~Keeper();
	int get_size();
	Figure* operator[] ( const int index);

	void insert(Figure* n_data);
	void remove(int index);
	void save();
	void load();
};
