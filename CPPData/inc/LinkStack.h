/*
 * LinkStack.h
 *
 *  Created on: 2016Äê11ÔÂ18ÈÕ
 *      Author: tla001
 */

#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#include "Common.h"
#include "Stack.h"
#include "LinkNode.h"

void LinkStackTest();
template<class T>
class LinkStack: public Stack<T> {
public:
	LinkStack(int initialCapacity = 10) {
		stackTop = NULL;
		stackSize = 0;
	}
	~LinkStack();
	bool empty() const {
		return stackSize == 0;
	}
	int size() const {
		return stackSize;
	}
	T& top() {
		if (stackSize == 0)
			throw stackEmpty();
		return stackTop->element;
	}
	void pop();
	void push(const T& theElement) {
		stackTop = new LinkNode<T>(theElement, stackTop);
		stackSize++;
	}
private:
	LinkNode<T>* stackTop;  // pointer to stack top
	int stackSize;           // number of elements in stack
};

template<class T>
LinkStack<T>::~LinkStack() {           // Destructor.
	while (stackTop != NULL) {           // delete top node
		LinkNode<T> *nextNode = stackTop->next;
		delete stackTop;
		stackTop = nextNode;
	}
}

template<class T>
void LinkStack<T>::pop() {           // Delete top element.
	if (stackSize == 0)
		throw stackEmpty();

	LinkNode<T> *nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize--;
}
#endif /* LINKSTACK_H_ */
