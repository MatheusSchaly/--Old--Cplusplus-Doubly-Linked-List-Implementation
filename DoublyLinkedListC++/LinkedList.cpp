/*
 * LinkedList.cpp
 *
 * Author:      Matheus Schaly
 * Created on:  Jul 17, 2017
 * Description: LinkedList implementation
 */

#include <iostream>

#include "Node.h"
using namespace std;

Node *head = NULL;
Node *tail = NULL;
int listSize = 0;

/*
 * Inserts a new node at the list's beginning
 * data: the data to be stored inside the new node
 */

void pushFront (int data) {
	Node *newNode = new Node(data);
	listSize++;
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode -> setNext(head);
	head -> setPrev(newNode);
	head = newNode;
	return;
}

/*
 * Inserts a new node at the list's ending
 * data: the data to be stored inside the new node
 */

void pushBack (int data) {
	Node *newNode = new Node(data);
	listSize++;
	if (tail == NULL) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode -> setPrev(tail);
	tail -> setNext(newNode);
	tail = newNode;
	return;
}

/*
 * Inserts a new node at the list
 * data: the data to be stored inside the new node
 * index: the index of the new node
 */

void add (int data, int index) {
	Node *newNode = new Node(data);
	Node *temp = head;
	if (temp == NULL) {
		listSize++;
		head = newNode;
		tail = newNode;
		return;
	}
	if (index == 0) {
		pushFront(data);
		return;
	}
	if (index == listSize) {
		pushBack(data);
		return;
	}
	listSize++;
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

void popFront () {
	if (head == NULL) {
		return;
	}
	listSize--;
	head = head -> getNext();
	if (head == NULL) {
		tail = NULL;
		return;
	}
	head -> setPrev(NULL);
}

/*
 * Removes the list's last node
 * data: the data to be stored inside the new node
 */

void popBack () {
	if (tail == NULL) {
		return;
	}
	listSize--;
	tail = tail -> getPrev();
	if (tail == NULL) {
		head = NULL;
		return;
	}
	tail -> setNext(NULL);
}

/*
 * Reverses the list
 */

void reverseList () {
	Node *current = head;
	if (head == NULL) {
		return;
	}
	Node *prev = NULL;
	tail = head;
	while (current != NULL) {
		prev = current -> getPrev();
		current -> setPrev(current -> getNext());
		current -> setNext(prev);
		current = current -> getPrev();
	}
	head = prev -> getPrev();
}

/*
 * Prints the whole list
 */

void printList () {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp -> getData() << " ";
		temp = temp -> getNext();
	}
	cout << "Size: " << listSize << endl;
}

/*
 * Prints the whole list in reversed order
 */

void printListReversed () {
	Node *temp = tail;
	while (temp != NULL) {
		cout << temp -> getData() << " ";
		temp = temp -> getPrev();
	}
	cout << "Size: " << listSize << endl;
}

int main() {
	pushFront(1); // 1
	pushFront(2); // 2 1
	printList(); // 2 1 Size: 2
	pushBack(3); // 2 1 3
	pushBack(4); // 2 1 3 4
	printList(); // 2 1 3 4 Size: 4
	printListReversed(); // 4 3 1 2 Size: 4
	popBack(); // 2 1 3
	printList(); // 2 1 3 Size: 3
	popFront(); // 1 3
	printList(); // 1 3 Size: 2
	pushBack(5); // 1 3 5
	pushFront(10); // 10 1 3 5;
	printListReversed(); // 5 3 1 10; Size: 5
	printList(); // 10 1 3 5 Size: 4
	reverseList(); // 5 3 1 10
	printList(); // 5 3 1 10 Size: 4
	popFront(); // 3 1 10
	popBack(); // 3 1
	printList(); // 3 1 Size: 2
	reverseList(); // 1 3
	printList(); // 1 3 Size: 2
	popBack(); // 1
	printList(); // 1 Size: 1
	popFront(); //
	printListReversed(); // Size: 0
	add(1, 1); // 1
	printList(); // 1 Size: 1
	add(2, 1); // 1 2
	add(3, 2); // 1 2 3
	add(0, 0); // 0 1 2 3
	add(6, 2); // 0 1 6 2 3
	reverseList(); // 3 2 6 1 0
	printList(); // 3 2 6 1 0 Size: 5
	popFront(); // 2 6 1 0
	popBack(); // 2 6 1
	printListReversed(); // 1 6 2 Size: 3
}
