#include "Node.h"
int Node::getValue() {
	return value;
}

Node* Node::getLchild() {
	return lchild;
}
Node* Node::getRchild() {
	return rchild;
}

void Node::setLchild(Node* node) {
	lchild = node;
}
void Node::setRchild(Node* node) {
	rchild = node;
}