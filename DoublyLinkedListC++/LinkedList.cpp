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

/*
 * Inserts a new node at the list's beginning
 * Data: data to be stored inside the new node
 */

void insertAtHead (int data) {
	Node *newNode = new Node(data);
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
 * Data: data to be stored inside the new node
 */

void insertAtTail (int data) {
	Node *newNode = new Node(data);
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
 * Removes the list's first node
 * Data: data to be stored inside the new node
 */

void removeFromHead () {
	if (head == NULL) {
		return;
	}
	head -> getNext() -> setPrev(NULL);
	head = head -> getNext();
}

/*
 * Removes the list's last node
 * Data: data to be stored inside the new node
 */

void removeFromTail () {
	if (tail == NULL) {
		return;
	}
	tail -> getPrev() -> setNext(NULL);
	tail = tail -> getPrev();
}

/*
 * Reverses the list
 */

void reverseList () {
	Node *temp = head;
	if (head == NULL) {
		return;
	}
	Node *next = temp -> getNext();
	// CONTINUE HERE
	while (temp != NULL) {
 		temp -> setNext(temp -> getPrev());
		temp -> setPrev(next);
		next = next -> getNext();
		next -> getPrev() -> setNext(temp);
		next -> getPrev() -> setPrev(next);
		temp = next -> getPrev();
	}
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
	cout << endl;
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
	cout << endl;
}

int main() {
	insertAtHead(1); // 1
	insertAtHead(2); // 2 1
	printList(); // 2 1
	insertAtTail(3); // 2 1 3
	insertAtTail(4); // 2 1 3 4
	printList(); // 2 1 3 4
	printListReversed(); // 4 3 1 2
	removeFromTail(); // 2 1 3
	printList(); // 2 1 3
	removeFromHead(); // 1 3
	printList(); // 1 3
	insertAtTail(5); // 1 3 5
	insertAtHead(10); // 10 1 3 5;
	printListReversed(); // 5 3 1 10;
	printList(); // 10 1 3 5

}
