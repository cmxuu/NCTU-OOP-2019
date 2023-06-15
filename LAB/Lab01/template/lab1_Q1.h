#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class MATRIX
{
public:

	MATRIX() : a(0), b(0), c(0), d(0) {}
	MATRIX(int i, int j, int k, int l) : a(i), b(j), c(k), d(l) {}

	void print();
	void add(MATRIX m);
	void multiple(MATRIX m);
	void det();

private:
	/*
	m = [a, b
		 c, d]
	*/
	int a, b;
	int c, d;

};

#endif // MATRIX_H_INCLUDED