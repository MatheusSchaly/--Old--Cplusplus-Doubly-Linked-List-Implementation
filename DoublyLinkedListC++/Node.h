/*
 * Node.h
 *
 * Author:      Matheus Schaly
 * Created on:  Jul 17, 2017
 * Description: Declares the Node object
 */

#ifndef NODE_H_
#define NODE_H_
using namespace std;

#include <iostream>

class Node {
	int data;
	Node *next, *prev;
public:
	Node (int data);
	int getData ();
	void setData (int data);
	Node* getNext ();
	void setNext (Node *next);
	Node* getPrev ();
	void setPrev (Node *prev);
};

#endif /* NODE_H_ */
