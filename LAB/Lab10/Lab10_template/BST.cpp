#include "BST.h"
void BST::insert(Node* insertNode) {
	if (root == NULL)
		root = insertNode;
	else
	{
		Node* parent = root, * current = root;
		while (current != NULL)
		{
			parent = current;
			if (insertNode->getValue() > current->getValue())
				current = current->getRchild();
			else
				current = current->getLchild();
		}
		if (insertNode->getValue() > parent->getValue())
			parent->setRchild(insertNode);
		else
			parent->setLchild(insertNode);
	}
}

int BST::search(int value, int mode) {
	if (mode == 1)
	{
		Node* temp = root;
		int pos = 1;
		while (temp != NULL)
		{
			if (value==temp->getValue())
				return pos;
			else
			{
				if (value > temp->getValue()){
					pos = pos * 2 + 1;
					temp = temp->getRchild();
				}
				else
				{
					pos = pos * 2;
					temp = temp->getLchild();
				}
			}
		}
		return -1;
	}
	else if (mode == 2)
	{
		Node* temp = root;
		std::vector<int> step;
		while (value != 1)
		{
			step.push_back(value);
			value /= 2;
		}
		int size = step.size();
		for (int i = 0; i < size; i++)
		{
			if (step.back() % 2 == 1)
				temp = temp->getRchild();
			else
				temp = temp->getLchild();
			step.pop_back();	
		}
		return temp->getValue();
	}
}

Node* BST::getRoot() {
	return root;
}