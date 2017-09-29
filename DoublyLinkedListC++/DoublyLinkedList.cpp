/*
 * DoublyLinkedList.cpp
 *
 * Author:      Matheus Schaly
 * Created on:  Jul 17, 2017
 * Description: Implements the Doubly Linked List object
 */

#include "Node.h"
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
	listSize = 0;
}

void DoublyLinkedList::setHead(Node *node) {
	head = node;
}

Node* DoublyLinkedList::getHead() {
	return head;
}

void DoublyLinkedList::setTail(Node *node) {
	tail = node;
}

Node* DoublyLinkedList::getTail() {
	return tail;
}

int DoublyLinkedList::getListSize() {
	return listSize;
}


DoublyLinkedList::~DoublyLinkedList() {
	if (listSize == 0) {
		return;
	}
	if (listSize == 1) {
		delete getHead();
		return;
	}
	Node *temp = getHead() -> getNext();
	while (temp != NULL) {
		delete temp -> getPrev();
		temp = temp -> getNext();
	}
	delete getHead();
	delete getTail();
	this -> printList();
}

void DoublyLinkedList::increaseListSize() {
	listSize++;
}

void DoublyLinkedList::decreaseListSize() {
	listSize--;
}

/*
 * Inserts a new node at the list's beginning
 * data: the data to be stored inside the new node
 */

void DoublyLinkedList::pushFront (int data) {
	Node *newNode = new Node(data);
	increaseListSize();
	if (getHead() == NULL) {
		setHead(newNode);
		setTail(newNode);
		return;
	}
	newNode -> setNext(getHead());
	getHead() -> setPrev(newNode);
	setHead(newNode);
	return;
}

/*
 * Inserts a new node at the list's ending
 * data: the data to be stored inside the new node
 */

void DoublyLinkedList::pushBack (int data) {
	Node *newNode = new Node(data);
	increaseListSize();
	if (getTail() == NULL) {
		setHead(newNode);
		setTail(newNode);
		return;
	}
	newNode -> setPrev(getTail());
	getTail() -> setNext(newNode);
	setTail(newNode);
	return;
}

/*
 * Inserts a new node at the list
 * data: the data to be stored inside the new node
 * index: the index of the new node
 */

void DoublyLinkedList::add (int data, int index) {
	Node *newNode = new Node(data);
	if (getHead() == NULL) {
		increaseListSize();
		setHead(newNode);
		setTail(newNode);
		return;
	}
	if (index == 0) {
		pushFront(data);
		return;
	}
	if (index == getListSize()) {
		pushBack(data);
		return;
	}
	increaseListSize();
	Node *temp = getHead();
	for (int i = 1; i < index; i++) {
		temp = temp -> getNext();
	}
	newNode -> setNext(temp -> getNext());
	newNode -> setPrev(temp);
	temp -> getNext() -> setPrev(newNode);
	temp -> setNext(newNode);
}

/*
 * Removes the list's first node
 * data: the data to be stored inside the new node
 */

void DoublyLinkedList::popFront () {
	if (getListSize() == 0) {
		return;
	}
	decreaseListSize();
	setHead(getHead() -> getNext());
	if (getHead() == NULL) {
		setTail(NULL);
		return;
	}
	delete getHead() -> getPrev();
	getHead() -> setPrev(NULL);
}

/*
 * Removes the list's last node
 * data: the data to be stored inside the new node
 */

void DoublyLinkedList::popBack () {
	if (getListSize() == 0) {
		return;
	}
	decreaseListSize();
	setTail(getTail() -> getPrev());
	if (getTail() == NULL) {
		setHead(NULL);
		return;
	}
	delete getTail() -> getNext();
	getTail() -> setNext(NULL);
}

/*
 * Reverses the list
 */

void DoublyLinkedList::reverseList () {
	if (getHead() == NULL) {
		return;
	}
	Node *current = getHead();
	Node *prev = NULL;
	setTail(getHead());
	while (current != NULL) {
		prev = current -> getPrev();
		current -> setPrev(current -> getNext());
		current -> setNext(prev);
		current = current -> getPrev();
	}
	setHead(prev -> getPrev());
}

/*
 * Prints the whole list
 */

void DoublyLinkedList::printList () {
	Node *temp = getHead();
	while (temp != NULL) {
		cout << temp -> getData() << " ";
		temp = temp -> getNext();
	}
	cout << "Size: " << getListSize() << endl;
}

/*
 * Prints the whole list in reversed order
 */

void DoublyLinkedList::printListReversed () {
	Node *temp = getTail();
	while (temp != NULL) {
		cout << temp -> getData() << " ";
		temp = temp -> getPrev();
	}
	cout << "Size: " << getListSize() << endl;
}
