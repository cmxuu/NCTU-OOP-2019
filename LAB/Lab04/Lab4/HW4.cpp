#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void findAllSort(string aStr, int x, int y);
int main()
{
	string aString;

	cout << "The program will print the all possible permutations of string." << endl;
	cout << "If you want to close the program, please enter \"-1\"." << endl;
	cout << "===============================================================" << endl << endl;

	cout << "Enter a string: ";
	cin >> aString;

	while (aString != "-1") {
		sort(aString.begin(), aString.end());
		findAllSort(aString, 0, aString.length() - 1);
		cout << endl;
		cout << "Enter a string: ";
		cin >> aString;
	}
	
	system("PAUSE");
	return 0;
}

void findAllSort(string aStr, int x, int y)
{
	if (x != y)
	{
		for (int i = x; i < aStr.length(); i++)
		{
			swap(aStr[x], aStr[i]);
			findAllSort(aStr, x + 1, y);
			swap(aStr[x], aStr[i]);
		}
	}
	else
	{
		cout << aStr << endl;
	}
}