/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/19/19
** Description: Implements source code for Queue class. 
** Queue is used for creating queue lists
*********************************************************************/
#include <iostream>
#include "Queue.hpp"
#include "QueueNode.hpp"

Queue::Queue() { 
	front = nullptr;
}

Queue::~Queue() {
	QueueNode *nodePtr = front;
	if (front != nullptr && nodePtr->getNext() != front) {
		while (nodePtr->getNext() != front) {
			QueueNode *garbage = nodePtr;
			nodePtr = nodePtr->getNext();
			delete garbage;
		}
	}
	delete nodePtr;
	front = nullptr;
}

/*********************************************************************
** Description: creates a node with a value equal to the parameter and
** sets the node to the back of the queue
*********************************************************************/
void Queue::addBack(int number) {
	QueueNode *nodePtr = front;//make a temporary pointer to reference nodes
  //if list is empty
	if(front == nullptr){
		front = new QueueNode(number, front, front);
		front->setNext(front);
		front->setPrev(front);
	}
  //if list has 1 element
	else if (front->getNext() == nullptr) {
		front->setNext(new QueueNode(number, front, front));
		nodePtr = front->getNext(); 
		front->setPrev(nodePtr);
	}
	else {
		nodePtr = front->getPrev();
		nodePtr->setNext(new QueueNode(number, nodePtr, front));
		nodePtr->getNext()->setPrev(nodePtr);
		nodePtr = nodePtr->getNext();
		nodePtr->setNext(front);
		front->setPrev(nodePtr);
	}
}

/*********************************************************************
** Description: removes a node from the front of the list and sets the 
** second node to the front pointer
*********************************************************************/
int Queue::removeFront() {
	if (!front) {
		std::cout << "There are no values in this list." << std::endl;
		return -1;
	}
	else if (front->getNext() == front) {
		delete front;
		front = nullptr;
	}
	else {
		QueueNode *nodePtr = front;
		if (front->getNext() != front) {//if there's more than one node in queue
			front->getPrev()->setNext(front->getNext());
			front = front->getNext();
			front->setPrev(nodePtr->getPrev());
		}
		else if (front->getNext() == front) {
			front = nullptr;
		}
		else {
			std::cout << "unexpected occured in removeFromHead()" << std::endl;
		}
		delete nodePtr;
	}
  return 1;
}

/*********************************************************************
** Description: displays the current value of the front node of the 
** queue
*********************************************************************/
QueueNode* Queue::getFront() {
	return this->front; 
}