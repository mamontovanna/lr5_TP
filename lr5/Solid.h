#pragma once

using namespace std;

class Solid :public Figure {
private:
	double a;
	int b;
	int c;
	string type;
	double V;
	string pict;
public:
	Solid();
	Solid(string type);
	Solid(const Solid& Solid_copy);
	~Solid();
	void set_type(string f_type);
	void set_a(double a);
	void set_b(double b);
	void set_c(double c);
	void set_V(double V);
	void set_pict(string pict);
	string get_type() const;
	double get_V() const;
	double get_a() const;
	double get_b() const;
	double get_c() const;
	string get_pict() const;

	virtual void show();
	virtual void saving();
	virtual void rewrite();
	virtual void redact(int item1, int item2, int item3);
	virtual double Per();
};
