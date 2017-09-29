/*
 * DoublyLinkedList.h
 *
 * Author:      Matheus Schaly
 * Created on:  Aug 14, 2017
 * Description: Declares the Doubly Linked List object
 */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include "Node.h"
#include <iostream>

using namespace std;

class DoublyLinkedList {
	Node *head, *tail;
	int listSize;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void setHead(Node *node);
	Node* getHead();
	void setTail(Node *node);
	Node* getTail();
	int getListSize();
	void increaseListSize();
	void decreaseListSize();
	void pushFront (int data);
	void pushBack (int data);
	void add (int data, int index);
	void popFront ();
	void popBack ();
	void reverseList ();
	void printList ();
	void printListReversed ();
};

#endif /* DOUBLYLINKEDLIST_H_ */
