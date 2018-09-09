/**
* Author- Nagendra Singh
* Date- 24/07/2018
*/
#include "Header.h"

void SinglyLinkedList::IncrementSize(){
	this->size++;
}
void SinglyLinkedList::DecrementSize(){ this->size--; }
SinglyLinkedList::SinglyLinkedList(){
	this->head = nullptr;
	this->size = 0;
}
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& rhs){
	this->head = nullptr;
	this->size = 0;
	nodePtr currentNodePtr = rhs.head;
	while (currentNodePtr != nullptr){
		this->Add(currentNodePtr->data);
		currentNodePtr = currentNodePtr->next;
	}
}
void SinglyLinkedList::Add(int data){
	nodePtr newNodePtr = new Node;
	newNodePtr->data = data;
	newNodePtr->next = nullptr;
	if (isEmpty()){
		this->head = newNodePtr;
	}
	else{
		nodePtr prevHeadPtr = this->head;
		this->head = newNodePtr;
		newNodePtr->next = prevHeadPtr;
	}
	IncrementSize();
}
bool SinglyLinkedList::Remove(int data){
	nodePtr prevNodePtr = nullptr;
	nodePtr currentNodePtr = head;
	if (isEmpty()){
		return false;
	}
	while (currentNodePtr != nullptr)
	{
		if (data == currentNodePtr->data){
			nodePtr nodeAfterCurrentPtr = currentNodePtr->next;
			if (prevNodePtr == nullptr){
				this->head = nodeAfterCurrentPtr;
			}
			else{
				prevNodePtr->next = nodeAfterCurrentPtr;
			}
			delete currentNodePtr;
			DecrementSize();
			return true;
		}
		prevNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
	}
	return false;
}
bool SinglyLinkedList::isEmpty() const{
	return this->head == nullptr;
}
void SinglyLinkedList::EmptyList(){
	nodePtr currentNodeptr;
	while (this->head != nullptr){
		currentNodeptr = this->head;
		this->head = this->head->next;
		delete currentNodeptr;
	}
	this->size = 0;
}
size_t SinglyLinkedList::Size() const{
	return this->size;
}
void SinglyLinkedList::Traverse() const{
	nodePtr currentNodePtr = this->head;
	while (currentNodePtr != nullptr){
		currentNodePtr = currentNodePtr->next;
	}
}
SinglyLinkedList::~SinglyLinkedList(){
	this->EmptyList();
}