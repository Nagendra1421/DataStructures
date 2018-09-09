/**
* Author- Nagendra Singh
* Date- 24/07/2018
*/
#pragma once
class SinglyLinkedList{
	typedef struct Node{
		int data;
		Node *next;
	}*nodePtr;
	nodePtr head;
	nodePtr tail;
	size_t size;
	void IncrementSize();
	void DecrementSize();
public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& rhs);
	void Add(int data);
	bool Remove(int data);
	bool isEmpty() const;
	void EmptyList();
	size_t Size() const;
	void Traverse() const;
	~SinglyLinkedList();
};

