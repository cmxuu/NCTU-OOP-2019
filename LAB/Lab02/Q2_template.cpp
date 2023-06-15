#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class PrimeFactorization {
private:
	int num1, num2;
	vector<int> num1_factor, num2_factor;
	
public:
	PrimeFactorization() {
		num1 = 1;
		num2 = 1;
	}
	PrimeFactorization(int _a, int _b) {
		num1 = _a;
		num2 = _b;
	}
	void Get_Prime_Factorization() {
		int i = 2;
		while (num1 > 1){
			if (num1%i == 0){
				num1_factor.push_back(i);
				num1 /= i;
			}
			else
				i++;	
		}
		i = 2;
		while (num2 > 1) {
			if (num2%i == 0) {
				num2_factor.push_back(i);
				num2 /= i;
			}
			else
				i++;
		}
	}

	void Print_Prime_Factorization() {
		cout << "num1_Prime_factor : \" ";
		for (unsigned int i = 0; i < num1_factor.size(); i++)
			cout << num1_factor[i] << " ";
		cout << "\"" << endl;
		cout << "num2_Prime_factor : \" ";
		for (unsigned int i = 0; i < num2_factor.size(); i++)
			cout << num2_factor[i] << " ";
		cout << "\"" << endl;
	}

	void Print_GCD_Factorization() {
		cout << "GCD_Prime_factor : \" ";
		int i = 0, j = 0, flag = -1;
		while (i != num1_factor.size() && j != num2_factor.size()){
			if (num1_factor[i] == num2_factor[j]) {
				cout << num1_factor[i] << " ";
				flag = 1;
				i++;
				j++;
			}
			else if (num1_factor[i] > num2_factor[j])
				j++;
			else
				i++;
		}
		if (flag == -1)	cout << "1 ";
		cout << "\"" << endl;
	}

};

int main() {
	int n;

	ifstream fin;
	fin.open("input.txt");

	fin >> n;
	for (int i = 0; i < n; i++) {

		int a, b;
		fin >> a >> b;

		cout << "num1 = " << a << endl;
		cout << "num2 = " << b << endl;

		PrimeFactorization PF(a, b);
		
		PF.Get_Prime_Factorization();
		PF.Print_Prime_Factorization();
		
		PF.Print_GCD_Factorization();
		
		cout << endl;

	}
	fin.close();
	system("PAUSE");
	return 0;
}