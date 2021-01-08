/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/19/19
** Description: Specifies the Queue class header. Queue is used for 
** creating doubly linked lists
*********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
class QueueNode;

class Queue {
protected:

	QueueNode *front;
public:
	Queue();
	~Queue();

	/*********************************************************************
	** Description: creates a node with a value equal to the parameter and
	** sets the node to the back of the queue
	*********************************************************************/
	void addBack(int number);

	/*********************************************************************
	** Description: removes a node from the front of the list and sets the
	** second node to the front pointer
	*********************************************************************/
	int removeFront();

	/*********************************************************************
	** Description: displays the current value of the front node of the
	** queue
	*********************************************************************/
	QueueNode* getFront();
};


#endif