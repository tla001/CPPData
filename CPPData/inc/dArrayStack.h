/*
 * ArrayStack.h
 *
 *  Created on: 2016Äê11ÔÂ18ÈÕ
 *      Author: tla001
 */

#ifndef DARRAYSTACK_H_
#define DARRAYSTACK_H_

#include "Common.h"
#include "ArrayList.h"
#include "Stack.h"

template<class T>
class dArrayStack: private ArrayList<T>, public Stack<T> {
public:
	dArrayStack(int initialCapacity = 10) :
			ArrayList<T>(initialCapacity) {
	}
	bool empty() const {
		return ArrayList < T > ::empty();
	}
	int size() const {
		return ArrayList < T > ::size();
	}
	T& top() {
		try {
			return get(ArrayList < T > ::size() - 1);
		} catch (illegalIndex) {
			throw stackEmpty();
		}
	}
	void pop() {
		try {
			erase(ArrayList < T > ::size() - 1);
		} catch (illegalIndex) {
			throw stackEmpty();
		}
	}
	void push(const T& theElement) {
		insert(ArrayList < T > ::size(), theElement);
	}
};

#endif /* DARRAYSTACK_H_ */
