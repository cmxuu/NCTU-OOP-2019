#include "lab1_Q1.h"
#include <iostream>

using namespace std;

void MATRIX::print()
{
	cout << "[" << a << " , " << b  << " , " << c << " , " << d << "]" <<endl;
}

void MATRIX::add(MATRIX m)
{
	this -> a += m.a;
	this -> b += m.b;
	this -> c += m.c;
	this -> d +=m.d;
}

void MATRIX::multiple(MATRIX m)
{
	int ori_a = this->a, ori_b = this->b, ori_c = this->c, ori_d = this->d;
	this -> a = (ori_a * m.a) + (ori_b * m.c) ;
	this -> b = (ori_a * m.b) + (ori_b * m.d) ;
	this -> c = (ori_c * m.a) + (ori_d * m.c) ;
	this -> d = (ori_c * m.b) + (ori_d * m.d) ;
}

void MATRIX::det() 
{
	int det = (this->a * this->d) - (this->b * this->c);
	cout << det << endl;
}