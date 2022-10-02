#pragma once
#include "Lib.h"
#include "Figure.h"
#include <string>
using namespace std;

class Flat :public Figure {
private:
	//тип, размеры, площадь, рисунок на экране
	double a;
	int b;
	int c;
	string type;
	string pict;
	double S;
public:
	Flat();
	Flat(string type);
	Flat(const Flat& Flat_copy);
	~Flat();

	void set_type(string f_type);
	void set_a(double a);
	void set_b(double b);
	void set_c(double c);
	void set_S(double S);
	void set_pict(string pict);
	string get_type() const;
	double get_S() const;
	double get_a() const;
	double get_b() const;
	double get_c() const;
	string get_pict() const;

	virtual void show() override;
	virtual void saving() override;
	virtual void rewrite() override;
	virtual void redact(int item1, int item2 = 0, int item3 = 0) override;
	virtual double Per();
};
