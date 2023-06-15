#pragma once
#include <iostream>
#include <fstream>


using namespace std;

class Vector
{
	private:
		float *arr;
		int currentIndex;
		int arrSize;

	public:
		//constructor
		Vector();
		Vector(int size);
		Vector(const Vector& V);
		~Vector();
		
		//setter
		void AddNumbertoArr(float number);

		//getter
		int getSize();

		float length();
		Vector normalize();

		//overload 
		Vector operator +(const Vector &v);
		void operator =(const Vector &v);
		Vector operator -(const Vector &v);

		//dot product
		float operator *(const Vector &v);

		//input output overload
		friend ifstream& operator >> (ifstream& in, Vector &v);
		friend ostream& operator << (ostream& out, const Vector &v);
	
};