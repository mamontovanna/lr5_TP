#pragma once
//abstract class
#include "Lib.h"
using namespace std;
class Figure
{
public:
	Figure() {};
	virtual ~Figure() {};
	virtual void show() = 0;
	virtual void saving() = 0;
	virtual void rewrite() = 0;
	virtual void redact(int item1, int item2, int item3) = 0;
	virtual double Per() = 0;

};
typedef struct Elem
{
	Figure* data;
	Elem* next;
} Elem;
