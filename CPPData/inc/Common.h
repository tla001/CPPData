/*
 * Common.h
 *
 *  Created on: 2016Äê11ÔÂ7ÈÕ
 *      Author: tla001
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * define some util class
 */

class illegalParameterValue {
public:
	illegalParameterValue() :
			message("Illegal parameter value") {
	}
	illegalParameterValue(string theMessage) {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};
class illegalIndex {
public:
	illegalIndex() :
			message("Illegal index value") {
	}
	illegalIndex(string theMessage) {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};
// matrix index out of bounds
class matrixIndexOutOfBounds {
public:
	matrixIndexOutOfBounds(string theMessage = "Matrix index out of bounds") {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};

// matrix size mismatch
class matrixSizeMismatch {
public:
	matrixSizeMismatch(string theMessage =
			"The size of the two matrics doesn't match") {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength) {
	if (newLength < 0)
		throw illegalParameterValue("new length must be >= 0");

	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}

// stack is empty
class stackEmpty {
public:
	stackEmpty(string theMessage = "Invalid operation on empty stack") {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};
// queue is empty
class queueEmpty {
public:
	queueEmpty(string theMessage = "Invalid operation on empty queue") {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};
// hash table is full
class hashTableFull {
public:
	hashTableFull(string theMessage = "The hash table is full") {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};
// Tree is empty
class emptyTree {
public:
	emptyTree(string theMessage = "Invalid operation on empty tree") {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};

struct player {
	int id, key;

	operator int() const {
		return key;
	}
};

// method undefined
class undefinedMethod {
public:
	undefinedMethod(string theMessage = "This method is undefined") {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};

template<class T>
bool make2dArray(T ** &x, int numberOfRows, int numberOfColumns) { // Create a two dimensional array.

	try {
		// create pointers for the rows
		x = new T *[numberOfRows];

		// get memory for each row
		for (int i = 0; i < numberOfRows; i++)
			x[i] = new int[numberOfColumns];
		return true;
	} catch (bad_alloc) {
		return false;
	}
}

template<class T>
void delete2dArray(T ** &theArray, int numberOfRows) { // Delete the two-dimensional array theArray.

	// delete the memory for each row
	for (int i = 0; i < numberOfRows; i++)
		delete[] theArray[i];

	// delete the row pointers
	delete[] theArray;
	theArray = 0;
}
#endif /* INC_COMMON_H_ */
