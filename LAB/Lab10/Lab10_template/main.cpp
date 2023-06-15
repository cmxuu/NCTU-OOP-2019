#include <iostream>
#include <fstream>
#include "BST.h"
#include "Node.h"
#include <string>
using namespace std;
void inOrderTraverse(Node* root) {
	// Inorder traverse all the node and print them out
	if (root != NULL)
	{
		inOrderTraverse(root->getLchild());
		cout << root->getValue() << " ";
		inOrderTraverse(root->getRchild());
	}
}
int main() {
	
	ifstream inFile;
	inFile.open("input.txt");

	BST BST_TREE;
	int num, x;
	string ch;
	
	inFile >> num;
	for (int i = 0; i < num; i++)
	{
		inFile >> x;
		Node *temp = new Node(x);
		BST_TREE.insert(temp);
	}
	while (inFile >> ch)
	{
		if (ch == "i")
		{
			inFile >> x;
			Node* temp = new Node(x);
			BST_TREE.insert(temp);
		}
		else if (ch == "sp")
		{
			inFile >> x;
			cout << BST_TREE.search(x, 1) << endl;
		}
		else if (ch == "sn")
		{
			inFile >> x;
			cout << BST_TREE.search(x, 2) << endl;
		}
		else if (ch == "p")
		{
			inOrderTraverse(BST_TREE.getRoot());
			cout << endl;
		}
			
	}

	inFile.close();
	
	system("pause");
	return 0;

}