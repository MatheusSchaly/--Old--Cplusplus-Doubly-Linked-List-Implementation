/*
 * main.cpp
 *
 * Author:      Matheus Schaly
 * Created on:  Aug 14, 2017 
 * Description: Creates a Doubly Linked List object to test it
 */

#include "DoublyLinkedList.h"

int main() {
	DoublyLinkedList *doublyLinkedList = new DoublyLinkedList();
	doublyLinkedList -> pushFront(1); // 1
	doublyLinkedList -> pushFront(2); // 2 1
	doublyLinkedList -> printList(); // 2 1 Size: 2
	doublyLinkedList -> pushBack(3); // 2 1 3
	doublyLinkedList -> pushBack(4); // 2 1 3 4
	doublyLinkedList -> printList(); // 2 1 3 4 Size: 4
	doublyLinkedList -> printListReversed(); // 4 3 1 2 Size: 4
	doublyLinkedList -> popBack(); // 2 1 3
	doublyLinkedList -> printList(); // 2 1 3 Size: 3
	doublyLinkedList -> popFront(); // 1 3
	doublyLinkedList -> printList(); // 1 3 Size: 2
	doublyLinkedList -> pushBack(5); // 1 3 5
	doublyLinkedList -> pushFront(10); // 10 1 3 5;
	doublyLinkedList -> printListReversed(); // 5 3 1 10; Size: 5
	doublyLinkedList -> printList(); // 10 1 3 5 Size: 4
	doublyLinkedList -> reverseList(); // 5 3 1 10
	doublyLinkedList -> printList(); // 5 3 1 10 Size: 4
	doublyLinkedList -> popFront(); // 3 1 10
	doublyLinkedList -> popBack(); // 3 1
	doublyLinkedList -> printList(); // 3 1 Size: 2
	doublyLinkedList -> reverseList(); // 1 3
	doublyLinkedList -> printList(); // 1 3 Size: 2
	doublyLinkedList -> popBack(); // 1
	doublyLinkedList -> printList(); // 1 Size: 1
	doublyLinkedList -> popFront(); //
	doublyLinkedList -> printListReversed(); // Size: 0
	doublyLinkedList -> add(1, 1); // 1
	doublyLinkedList -> printList(); // 1 Size: 1
	doublyLinkedList -> add(2, 1); // 1 2
	doublyLinkedList -> add(3, 2); // 1 2 3
	doublyLinkedList -> add(0, 0); // 0 1 2 3
	doublyLinkedList -> add(6, 2); // 0 1 6 2 3
	doublyLinkedList -> reverseList(); // 3 2 6 1 0
	doublyLinkedList -> printList(); // 3 2 6 1 0 Size: 5
	doublyLinkedList -> popFront(); // 2 6 1 0
	doublyLinkedList -> popBack(); // 2 6 1
	doublyLinkedList -> printListReversed(); // 1 6 2 Size: 3
	delete doublyLinkedList;
}




