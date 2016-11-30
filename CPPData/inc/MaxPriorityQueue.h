/*
 * MaxPriorityQueue.h
 *
 *  Created on: 2016��11��22��
 *      Author: tla001
 */

#ifndef INC_MAXPRIORITYQUEUE_H_
#define INC_MAXPRIORITYQUEUE_H_
#include "Common.h"

template<class T>
class maxPriorityQueue {
public:
	virtual ~maxPriorityQueue() {
	}
	virtual bool empty() const = 0;
	// return true iff queue is empty
	virtual int size() const = 0;
	// return number of elements in queue
	virtual const T& top() = 0;
	// return reference to the max element
	virtual void pop() = 0;
	// remove the top element
	virtual void push(const T& theElement) = 0;
	// add theElement to the queue
};

#endif /* INC_MAXPRIORITYQUEUE_H_ */
