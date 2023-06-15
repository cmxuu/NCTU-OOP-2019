#ifndef _Matrix_
#define _Matrix_

#include<iostream>
#include<vector>

using namespace std;

class matrix
{
public:
	vector<vector<int> > M;
	
	matrix();
	matrix(int m, int n);
	matrix(vector<vector<int> > &m);
	void Add(matrix m1);
	void Sub(matrix m1);
	matrix Mul(matrix m1);
	void Inverse();
	bool IsSameShape(matrix m1);
	bool SquareMatrix();
	void GetDet();
	int Det(vector<vector<int> > &m);
	void Print();
};


#endif // !_Matrix_

