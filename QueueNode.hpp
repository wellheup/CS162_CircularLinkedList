/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/19/19
** Description: Specifies the QueueNode struct header. 
** QueueNode is used for creating single value nodes for queued lists
*********************************************************************/
#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

class QueueNode {
protected:
	int val;
	QueueNode *next, *prev;
public:
	/*********************************************************************
	** Description: 3 parameter constructor defines a node with received
	** integer value and pointers to the next and previous nodes in the
	** queue
	*********************************************************************/
	QueueNode(int val1, QueueNode *next1 = nullptr, QueueNode *prev1 = nullptr);
	~QueueNode();

	//getters and setters	
	int getVal();
	void setVal(int val);
	QueueNode* getNext();
	void setNext(QueueNode* next);
	QueueNode* getPrev();
	void setPrev(QueueNode* prev);
};
#endif