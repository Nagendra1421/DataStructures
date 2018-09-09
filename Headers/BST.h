/**
* Author- Nagendra Singh
* Date- 24/07/2018
*/
#pragma once	
class BST{
private:
	typedef struct Node{
		int data;
		Node *leftChild;
		Node *rightChild;
	}*nodePtr;
	nodePtr root;
	size_t sz;
	void IncrementSize();
	void DecrementSize();
	nodePtr CreateNewNode(int data) const;
	nodePtr GetmaxNode(nodePtr currentNode) const;
	nodePtr GetMinNode(nodePtr currentNode) const;
	void EmptyTree(nodePtr currentNodePtr) const;
	void Addnode(nodePtr nodePtr, int datatoAdd) const;
	nodePtr RemoveNode(nodePtr currentNode, int dataToRemove) const;
public:
	BST();
	void Add(int data);
	void Remove(int data);
	~BST();
};