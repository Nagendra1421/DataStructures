/**
* Author- Nagendra Singh
* Date- 23/07/2018
*/
#include"Header.h"

struct EmptyQueueException :public std::exception{
	const char* what() const throw(){
		return "C++ Exception: Queue is Empty ...";
	}
};

template<class T>
typename Queue<T>::nodePtr Queue<T>::CreateNode(T data){
	nodePtr newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}
template <class T>
void Queue<T>::EmptyQueue(){
	while (this->head != nullptr){
		nodePtr current_node = this->head;
		this->head = this->head->next;
		delete current_node;
	}
	this->tail = nullptr;
	this->size = 0;
}
template<class T>
Queue<T>::Queue(){
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}
template<class T>
Queue<T>::~Queue(){
	this->EmptyQueue();
}
template<class T>
void Queue<T>::Enqueue(const T data){
	nodePtr newNode = CreateNode(data);
	if (this->isEmpty()){
		this->head = newNode;
	}
	else{
		if (this->tail == nullptr){
			this->tail = newNode;
			this->head->next = this->tail;
		}
		else{
			nodePtr prevTail = this->tail;
			this->tail = newNode;
			prevTail->next = this->tail;
		}
	}
	++this->size;
}

template<class T>
T Queue<T>::dequeue(){
	T dataToReturn;
	if (this->isEmpty()){
		throw EmptyQueueException();
	}
	else{
		dataToReturn = this->head->data;
		if (this->tail == nullptr){
			delete this->head;
		}
		else{
			nodePtr prevHead = this->head;
			this->head = this->head->next;
			delete prevHead;
		}
	}
	--this->size;
	return dataToReturn;
}

template<class T>
int Queue<T>::Size() const{
	return this->size;
}
template<class T>
bool Queue<T>::isEmpty() const{
	return this->head == nullptr;
}
template<class T>
void Queue<T>::Print() const{
	nodePtr current_node = this->head;
	int counter = 0;
	while (counter < this->size){
		std::cout << current_node->data << " ";
		current_node = current_node->next;
		++counter;
	}
}