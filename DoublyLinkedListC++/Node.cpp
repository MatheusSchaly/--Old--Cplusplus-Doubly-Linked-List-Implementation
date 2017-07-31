/*
 * Node.cpp
 *
 * Author:      Matheus Schaly
 * Created on:  Jul 17, 2017
 * Description: Implements the Node object
 */

#include "Node.h"

Node::Node (int data) {
	this -> data = data;
	prev = NULL;
	next = NULL;
}

int Node::getData () {
	return data;
}

void Node::setData (int data) {
	this -> data = data;
}

Node* Node::getNext () {
	return next;
}

void Node::setNext (Node *next) {
	this -> next = next;
}

Node* Node::getPrev () {
	return prev;
}

void Node::setPrev (Node *prev) {
	this -> prev = prev;
}



