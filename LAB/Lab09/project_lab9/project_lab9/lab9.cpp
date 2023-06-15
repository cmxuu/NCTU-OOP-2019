#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void headSort(vector<int>& vec);
void maxHeap(vector<int>& vec, int root, int len);
void printVec(vector<int> vec);

int main()
{
	int num,x;
	vector<int> vec;

	ifstream inFile;
	inFile.open("input.txt");

	while (inFile >> num)
	{
		vec.clear();
		vec.push_back(0);
		for (int i = 0; i < num; i++)
		{
			inFile >> x;
			vec.push_back(x);
		}
		cout << "Before: ";
		printVec(vec);
		headSort(vec);
		cout << "After : ";
		printVec(vec);
		cout << endl;
	}

	inFile.close();

	system("PAUSE");
	return 0;
}


//         1
//      2     3
//    4  5   6  7 
//   8 9 

void headSort(vector<int>& vec) 
{
	int size = vec.size() - 1;
		
	for (int i = size / 2; i >= 1; i--)		//﹍て
		maxHeap(vec, i, size);   
	
	for (int i = size; i > 1; i--)
	{
		swap(vec[1], vec[i]);				//程メ程ソ
		size--;								//逼メ帝
		maxHeap(vec, 1, size);				//穝秸俱child才maxHeap
	}
}

void maxHeap(vector<int>& vec,int root,int len)
{													
	int left = root * 2, right = root * 2 + 1, key = root;		 

	if (left <= len && vec[left] > vec[key])	key = left;		//т程index
	if (right <= len && vec[right] > vec[key])	key = right;
	
	if (key != root)
	{
		swap(vec[root], vec[key]);								//р程传root
		maxHeap(vec, key, len);									//穝秸俱child才maxHeap
	}
}

void printVec(vector<int> vec)
{
	for (int i = 1; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}