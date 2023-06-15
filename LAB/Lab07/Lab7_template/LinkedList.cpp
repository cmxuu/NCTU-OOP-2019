#include"LinkedList.h"

LinkedList::LinkedList()
{
	//Constructor
	Head = NULL;
}

void LinkedList::Push_back(int x)
{
	//TODO : Insert a node to the end of the linked list, the node's value is x.
	ListNode *newNode = new ListNode;
	newNode->val = x;
	newNode->next = NULL;
	if (Head == NULL)
		Head=newNode;
	else
	{
		ListNode *temp = Head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
}

void LinkedList::Push_front(int x)
{
	//TODO : Insert a node to the front of the linked list, the node's value is x.
	ListNode *newNode = new ListNode;
	newNode->val = x;
	newNode->next = Head;
	Head = newNode;
}

void LinkedList::Insert(int index,int x)
{
	//TODO : Insert a node to the linked list at position "index", the node's value is x.
	//The index of the first node in the linked list is 0.
	ListNode *newNode = new ListNode, *temp = Head;
	newNode->val = x;
	if (Head == NULL)
	{
		newNode->next = NULL;
		Head = newNode;
	}
	else
	{
		if (index == 0)
		{
			newNode->next = Head;
			Head = newNode;
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
				temp = temp->next;
			if (temp->next != NULL)
				newNode->next = temp->next;
			else
				newNode->next = NULL;
			temp->next = newNode;
		}
	}
}

void LinkedList::Delete(int index)
{
	//TODO : Remove the node with index "index" in the linked list.
	if (index == 0)
		Head = Head->next;
	else
	{
		ListNode *temp = Head, *del;
		for (int i = 0; i < index - 1; i++)
			temp = temp->next;
		del = temp->next;
		temp->next = del->next;
		delete del;
	}
}

void LinkedList::Reverse()
{
	//TODO : Reverse the linked list.
	ListNode *front = NULL, *now = Head, *behind = Head->next;
	while (behind != NULL)
	{
		now->next = front;
		front = now;
		now = behind;
		behind = behind->next;
	}
	now->next = front;
	Head = now;
}

void LinkedList::Print()
{
	cout << "List: ";
	//TODO : Print all the elements in the linked list in order.
	ListNode *temp;
	for (temp = Head; temp != NULL; temp = temp->next)
		cout << temp->val << " ";
}

LinkedList::~LinkedList()
{
	//Destructor
	ListNode *now = Head,*next;
	while (now != NULL)
	{
		next = now->next;
		delete now;
		now = next;
	}
	Head = NULL;
}
