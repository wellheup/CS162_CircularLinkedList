/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/19/19
** Description: Implements source code for QueueNode class header. 
** QueueNode is used for creating single value nodes for queued lists
*********************************************************************/
#include <iostream>
#include "QueueNode.hpp"

/*********************************************************************
** Description: 3 parameter constructor defines a node with received
** integer value and pointers to the next and previous nodes in the 
** queue
*********************************************************************/
QueueNode::QueueNode(int val1, QueueNode * next1, QueueNode * prev1) {
	val = val1;
	next = next1;
	prev = prev1;
}

QueueNode::~QueueNode() {
	this->next = nullptr;
	this->prev = nullptr;
}

//getters and setters
int QueueNode::getVal() {
	return this->val;
}

void QueueNode::setVal(int val) {
	this->val = val;
}

QueueNode * QueueNode::getNext() {
	return this->next;
}

void QueueNode::setNext(QueueNode * next) {
	this->next = next;
}

QueueNode * QueueNode::getPrev() {
	return this->prev;
}

void QueueNode::setPrev(QueueNode * prev) {
	this->prev = prev;
}
