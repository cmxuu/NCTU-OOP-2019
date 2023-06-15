#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
class BST {
public:
	BST() {
		root = NULL;
	}
	void insert(Node* insertNode);
    int search(int value,int mode);
	Node* getRoot();
private:
	Node* root;
};
