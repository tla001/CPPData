/*
 * ArrayList.cpp
 *
 *  Created on: 2016年11月7日
 *      Author: tla001
 */

#include "Common.h"
#include <ArrayList.h>

template<class T>
ArrayList<T>::ArrayList(int initialCapacity) {
	if (initialCapacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& theList) {
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}
template<class T>
void ArrayList<T>::checkIndex(int theIndex) const {
	if (theIndex < 0 || theIndex >= listSize) {
		ostringstream ss;
		ss << "index= " << theIndex << " size= " << listSize;
		throw illegalIndex(ss.str());
	}
}

template<class T>
T& ArrayList<T>::get(int theIndex) const {
	checkIndex(theIndex);
	return element[theIndex];
}

template<class T>
int ArrayList<T>::indexOf(const T& theElement) const {
	int theIndex = (int) (find(element, element + listSize, theElement)
			- element);
	if (theIndex == listSize)
		return -1;
	else
		return theIndex;
}
template<class T>
void ArrayList<T>::erase(int theIndex) {
	checkIndex(theIndex); //检查索引
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T(); //调用析构函数
}
template<class T>
void ArrayList<T>::insert(int theIndex, const T&theElement) {
	if (theIndex < 0 || theIndex > listSize) {
		ostringstream ss;
		ss << "index= " << theIndex << " size= " << listSize;
		throw illegalIndex(ss.str());
	}
	if (listSize == arrayLength) {
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	copy_backward(element + theIndex, element + listSize,
			element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}
template<class T>
void ArrayList<T>::output(ostream& out) const {
	copy(element, element + listSize, ostream_iterator < T > (cout, "  "));
}
template<class T>
ostream& operator<<(ostream& out, const ArrayList<T>& x) {
	x.output(out);
	return out;
}
void ArrayListTest() {
	// test constructor
	linearList<double> *x = new ArrayList<double>(20);
	ArrayList<int> y(2), z;

	// test capacity
	cout << "Capacity of x, y and z = " << ((ArrayList<double>*) x)->capacity()
			<< ", " << y.capacity() << ", " << z.capacity() << endl;

	// test size
	cout << "Initial size of x, y, and z = " << x->size() << ", " << y.size()
			<< ", " << z.size() << endl;

	// test empty
	if (x->empty())
		cout << "x is empty" << endl;
	else
		cout << "x is not empty" << endl;
	if (y.empty())
		cout << "y is empty" << endl;
	else
		cout << "y is not empty" << endl;

	// test insert
	y.insert(0, 2);
	y.insert(1, 6);
	y.insert(0, 1);
	y.insert(2, 4);
	y.insert(3, 5);
	y.insert(2, 3);
	cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
	cout << "Size of y = " << y.size() << endl;
	cout << "Capacity of y = " << y.capacity() << endl;
	if (y.empty())
		cout << "y is empty" << endl;
	else
		cout << "y is not empty" << endl;
	y.output(cout);
	cout << endl << "Testing overloaded <<" << endl;
	cout << y << endl;

	// test indexOf
	int index = y.indexOf(4);
	if (index < 0)
		cout << "4 not found" << endl;
	else
		cout << "The index of 4 is " << index << endl;

	index = y.indexOf(7);
	if (index < 0)
		cout << "7 not found" << endl;
	else
		cout << "The index of 7 is " << index << endl;

	// test get
	cout << "Element with index 0 is " << y.get(0) << endl;
	cout << "Element with index 3 is " << y.get(3) << endl;

	// test erase
	y.erase(1);
	cout << "Element 1 erased" << endl;
	cout << "The list is " << y << endl;
	y.erase(2);
	cout << "Element 2 erased" << endl;
	cout << "The list is " << y << endl;

	cout << "Size of y = " << y.size() << endl;
	cout << "Capacity of y = " << y.capacity() << endl;
	if (y.empty())
		cout << "y is empty" << endl;
	else
		cout << "y is not empty" << endl;

	try {
		y.insert(-3, 0);
	} catch (illegalIndex e) {
		cout << "Illegal index exception" << endl;
		cout << "Insert index must be between 0 and list size" << endl;
		e.outputMessage();
	}

	// test copy constructor
	ArrayList<int> w(y);
	y.erase(0);
	y.erase(0);
	cout << "w should be old y, new y has first 2 elements removed" << endl;
	cout << "w is " << w << endl;
	cout << "y is " << y << endl;

	// a few more inserts, just for fun
	y.insert(0, 4);
	y.insert(0, 5);
	y.insert(0, 6);
	y.insert(0, 7);
	cout << "y is " << y << endl;
}
