/*
 * Stack.h
 *
 *  Created on: 2016Äê11ÔÂ18ÈÕ
 *      Author: tla001
 */

#ifndef INC_STACK_H_
#define INC_STACK_H_

#include "Common.h"

template<class T>
class Stack {
public:
	virtual ~Stack() {
	}
	virtual bool empty() const = 0;
	// return true iff stack is empty
	virtual int size() const = 0;
	// return number of elements in stack
	virtual T& top() = 0;
	// return reference to the top element
	virtual void pop() = 0;
	// remove the top element
	virtual void push(const T& theElement) = 0;
	// insert theElement at the top of the stack
};

#endif /* INC_STACK_H_ */
