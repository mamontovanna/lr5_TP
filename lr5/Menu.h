#pragma once
#include "Lib.h"
class Menu {
protected:
	Keeper list;
	Figure* figures;
	int exit = 1;
public:
	void main_menu();
	int show_options();
	void show_all_figures();
	void change_data();
	void add_new();
	void save_to_file();
	void load_from_file();
	void delete_figure();
	void find_per();
	void exit_from_programm();
};