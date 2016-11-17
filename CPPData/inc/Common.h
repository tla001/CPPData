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
#endif /* INC_COMMON_H_ */
