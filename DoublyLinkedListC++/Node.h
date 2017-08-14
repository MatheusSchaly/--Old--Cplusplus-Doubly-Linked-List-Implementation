/*
 * Node.h
 *
 * Author:      Matheus Schaly
 * Created on:  Jul 17, 2017
 * Description: Declares the Node object
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

using namespace std;

class Node {
	int data;
	Node *next, *prev;
public:
	Node (int data);
	void setData (int data);
	int getData ();
	void setNext (Node *next);
	Node* getNext ();
	void setPrev (Node *prev);
	Node* getPrev ();
};

#endif /* NODE_H_ */
