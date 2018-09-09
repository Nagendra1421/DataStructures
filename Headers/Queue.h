/**
* Author- Nagendra Singh
* Date- 23/07/2018
*/
#pragma once
template<class T> class Queue{
	typedef struct Node{
		T data;
		Node* next;
	}*nodePtr;
private:
	nodePtr head;
	nodePtr tail;
	int size;
	nodePtr CreateNode(T data);
	void EmptyQueue();
public:
	Queue();
	~Queue();
	void Enqueue(const T data);
	T dequeue();
	int Size() const;
	bool isEmpty() const;
	void Print() const;
};

