/*
 * LinkQueue.h
 *
 *  Created on: 2016Äê11ÔÂ19ÈÕ
 *      Author: tla001
 */

#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

#include "Common.h"
#include "Queue.h"
#include "LinkNode.h"

void LinkQueueTest();

template<class T>
class LinkQueue: public Queue<T> {
public:
	LinkQueue(int initialCapacity = 10) {
		queueFront = NULL;
		queueSize = 0;
	}
	~LinkQueue();
	bool empty() const {
		return queueSize == 0;
	}
	int size() const {
		return queueSize;
	}
	T& front() {
		if (queueSize == 0)
			throw queueEmpty();
		return queueFront->element;
	}
	T& back() {
		if (queueSize == 0)
			throw queueEmpty();
		return queueBack->element;
	}
	void pop();
	void push(const T&);
private:
	LinkNode<T>* queueFront;  // pointer to queue front
	LinkNode<T>* queueBack;   // pointer to queue back
	int queueSize;             // number of elements in queue
};

template<class T>
LinkQueue<T>::~LinkQueue() {             // Destructor.
	while (queueFront != NULL) {             // delete front node
		LinkNode<T> *nextNode = queueFront->next;
		delete queueFront;
		queueFront = nextNode;
	}
}

template<class T>
void LinkQueue<T>::pop() {             // Delete front element.
	if (queueFront == NULL)
		throw queueEmpty();

	LinkNode<T> *nextNode = queueFront->next;
	delete queueFront;
	queueFront = nextNode;
	queueSize--;
}

template<class T>
void LinkQueue<T>::push(const T& theElement) { // Add theElement to back of queue.

	// create node for new element
	LinkNode<T> *newNode = new LinkNode<T>(theElement, NULL);

	// add new node to back of queue
	if (queueSize == 0)
		queueFront = newNode;       // queue empty
	else
		queueBack->next = newNode;  // queue not empty
	queueBack = newNode;

	queueSize++;
}

#endif /* LINKQUEUE_H_ */
