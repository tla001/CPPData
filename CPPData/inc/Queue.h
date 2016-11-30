/*
 * Queue.h
 *
 *  Created on: 2016Äê11ÔÂ19ÈÕ
 *      Author: tla001
 */

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_
#include "Common.h"
template<class T>
class Queue {
public:
	virtual ~Queue() {
	}
	virtual bool empty() const = 0;
	// return true iff queue is empty
	virtual int size() const = 0;
	// return number of elements in queue
	virtual T& front() = 0;
	// return reference to the front element
	virtual T& back() = 0;
	// return reference to the back element
	virtual void pop() = 0;
	// remove the front element
	virtual void push(const T& theElement) = 0;
	// add theElement at the back of the queue
};
#endif /* INC_QUEUE_H_ */
