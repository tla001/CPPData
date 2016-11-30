/*
 * ArrayStack.h
 *
 *  Created on: 2016Äê11ÔÂ18ÈÕ
 *      Author: tla001
 */

#ifndef INC_ARRAYSTACK_H_
#define INC_ARRAYSTACK_H_

#include "Common.h"
#include "Stack.h"

void ArrayStackTest();

template<class T>
class ArrayStack: public Stack<T> {
public:
	ArrayStack(int initialCapacity = 10);
	~ArrayStack() {
		delete[] stack;
	}
	bool empty() const {
		return stackTop == -1;
	}
	int size() const {
		return stackTop + 1;
	}
	T& top() {
		if (stackTop == -1)
			throw stackEmpty();
		return stack[stackTop];
	}
	void pop() {
		if (stackTop == -1)
			throw stackEmpty();
		stack[stackTop--].~T();  // destructor for T
	}
	void push(const T& theElement);
private:
	int stackTop;         // current top of stack
	int arrayLength;      // stack capacity
	T *stack;           // element array
};

template<class T>
ArrayStack<T>::ArrayStack(int initialCapacity) {           // Constructor.
	if (initialCapacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}

template<class T>
void ArrayStack<T>::push(const T& theElement) {      // Add theElement to stack.
	if (stackTop == arrayLength - 1) {           // no space, double capacity
		changeLength1D(stack, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	// add at stack top
	stack[++stackTop] = theElement;
}

#endif /* INC_ARRAYSTACK_H_ */
