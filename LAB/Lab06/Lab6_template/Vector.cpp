#include "Vector.h"

Vector::Vector()
{
	arr = new float[0];
	arrSize = 0;
	currentIndex = 0;
}

Vector::Vector(int size)
{
	//TODO: Dynamic allocate array by the size  
	arr = new float[size];
	arrSize = size;
}

Vector::Vector(const Vector& V)
{
	//TODO: Copy Constructor 
	arr = new float[V.arrSize];
	for (int i = 0; i < V.arrSize; i++)
		arr[i] = V.arr[i];
	arrSize = V.arrSize;
}

Vector::~Vector()
{
	delete[] arr;
}

void Vector::AddNumbertoArr(float number)
{
	//TODO: Input a number into array
	float *newArr = new float[arrSize + 1];
	for (int i = 0; i < arrSize; i++)
		newArr[i] = arr[i];
	newArr[arrSize] = number;
	arr = newArr;
	arrSize++;
}

int Vector::getSize()
{
	//TODO: Return the array size
	return arrSize;
}

float Vector::length()
{
	//TODO: Compute the length of vector and return it
	float ans = 0;
	for (int i = 0; i < arrSize; i++)
		ans += (arr[i] * arr[i]);
	return sqrt(ans);
}

Vector Vector::normalize()
{
	//TODO: Normalize the vector and return it
	Vector newArr(arrSize);
	float len = length();
	for (int i = 0; i < arrSize; i++)
		newArr.arr[i] = arr[i] / len;
	return newArr;
}

Vector Vector::operator+(const Vector &v)
{
	//TODO: Overload the plus operator +. 
	//Then we can use more intuitively way to add our vector (like v1 + v2).
	//Return the result of v1 + v2
	Vector newArr(arrSize);
	for (int i = 0; i < arrSize; i++)
		newArr.arr[i] = arr[i] + v.arr[i];
	return newArr;
}

void Vector::operator=(const Vector &v)
{
	//TODO: Overload the assign operator =.
	//Then we can use more intuitively way to assign out vector (like v1 = v2).
	arr = new float[v.arrSize];
	arrSize = v.arrSize;
	for (int i = 0; i < v.arrSize; i++)
		arr[i] = v.arr[i];
}

Vector  Vector::operator-(const Vector &v)
{
	//TODO: Overload the subtract operator -.
	//Then we can use more intuitively way to subtract out vector (like v1 - v2).
	//Return the result of v1 - v2
	Vector newArr(arrSize);
	for (int i = 0; i < arrSize; i++)
		newArr.arr[i] = arr[i] - v.arr[i];
	return newArr;
}

float  Vector::operator*(const Vector &v)
{
	//TODO: Overload the operator * as dot product.
	//Return the dot product result of two vector
	float ans = 0;
	for (int i = 0; i < arrSize; i++)
		ans += (arr[i] * v.arr[i]);
	return ans;
}

ifstream & operator>>(ifstream & in, Vector &v)
{
	//TODO: Overload the >> operator.
	//Read the input.txt file and store vector in v
	int num;
	float value;
	in >> num;
	for (int i = 0; i < num; i++)
	{
		in >> value;
		v.AddNumbertoArr(value);
	}
	return in;
}

ostream & operator<<(ostream & out, const Vector & v)
{
	//TODO: Overload the << operator.
	//Output the vector v
	
	out << "(" << v.arr[0];
	for (int i = 1; i < v.arrSize; i++)
		out << ", " << v.arr[i];
	out << ")";
	
	return out;
}
