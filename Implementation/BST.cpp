/**
* Author- Nagendra Singh
* Date- 24/07/2018
*/
#include "Header.h"
void BST::IncrementSize(){ this->sz++; }
void BST::DecrementSize(){ this->sz--; }
BST::nodePtr BST::GetmaxNode(nodePtr currentNode)const{
	nodePtr result = currentNode;
	while (currentNode->rightChild != nullptr){
		result = currentNode->rightChild;
	}
	return result;
}
BST::nodePtr BST::GetMinNode(nodePtr currentNode)const{
	nodePtr res = currentNode;
	while (currentNode->leftChild != nullptr){
		res = currentNode->leftChild;
	}
	return res;
}
void BST::Addnode(nodePtr nodPtr, int dataToAdd)const{
	if (nodPtr == nullptr){ return; }
	else{
		int data = nodPtr->data;
		if (data > dataToAdd){
			if (nodPtr->leftChild == nullptr){
				nodPtr->leftChild = CreateNewNode(dataToAdd);
			}
			else{
				Addnode(nodPtr->rightChild, dataToAdd);
			}
		}
		else{
			if (nodPtr->rightChild == nullptr){
				nodPtr->rightChild = CreateNewNode(dataToAdd);
			}
			else{
				Addnode(nodPtr->rightChild, dataToAdd);
			}
		}
	}
}
BST::nodePtr BST::RemoveNode(nodePtr currentNode, int dataToRemove)const{
	if (currentNode == nullptr){ return currentNode; }
	int currentData = currentNode->data;
	nodePtr leftChild = currentNode->leftChild;
	nodePtr rightChild = currentNode->rightChild;
	if (currentData == dataToRemove){
		if (leftChild == nullptr && rightChild == nullptr){
			delete currentNode;
			return nullptr;
		}
		if (leftChild == nullptr){
			delete currentNode;
			return rightChild;
		}
		else if (rightChild == nullptr){
			delete currentNode;
			return leftChild;
		}
		else{
			nodePtr maxNodeFromLeftSubTree = GetmaxNode(leftChild);
			nodePtr nodeToDelete = currentNode;
			currentNode->data = maxNodeFromLeftSubTree->data; maxNodeFromLeftSubTree;
			currentNode->leftChild = RemoveNode(leftChild, maxNodeFromLeftSubTree->data);
			return currentNode;
		}
	}
	else if (currentData>dataToRemove){
		currentNode->leftChild = RemoveNode(leftChild, dataToRemove);
	}
	else{
		currentNode->rightChild = RemoveNode(rightChild, dataToRemove);
	}
	return currentNode;
}
BST::nodePtr BST::CreateNewNode(int data)const{
	nodePtr node = new Node;
	node->data = data;
	node->leftChild = nullptr;
	node->rightChild = nullptr;
	return node;
}
void BST::Add(int data){
	if (this->root == nullptr){
		this->root = CreateNewNode(data);
	}
	else{
		Addnode(this->root, data);
	}
	IncrementSize();
}
void BST::Remove(int data){
	if (this->root == nullptr){
		return;
	}
	RemoveNode(this->root, data);
}
BST::BST() :sz(0)
{
	this->root = nullptr;
}


BST::~BST()
{
}