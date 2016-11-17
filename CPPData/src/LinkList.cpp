/*
 * LinkList.cpp
 *
 *  Created on: 2016Äê11ÔÂ10ÈÕ
 *      Author: tla001
 */

#include "LinkList.h"

template<class T>
LinkList<T>::LinkList(int initialCapacity) {
	if (initialCapacity < 1) {
		ostringstream s;
		s << "Initial capacity =" << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}
template<class T>
LinkList<T>::LinkList(const LinkList<T>&theList) {
	listSize = theList.listSize;
	if (listSize == 0) {
		firstNode = NULL;
		return;
	}

	LinkNode < T > *sourceNode = theList.firstNode;
	firstNode = new LinkNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	LinkNode < T > *targetNode = firstNode;

	while (sourceNode != NULL) {
		targetNode->next = new LinkNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}
template<class T>
LinkList<T>::~LinkList() {
	while (firstNode != NULL) {
		LinkNode < T > *nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}
template<class T>
void LinkList<T>::checkIndex(int theIndex) const { // Verify that theIndex is between 0 and listSize - 1.
	if (theIndex < 0 || theIndex >= listSize) {
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

}
template<class T>
T& LinkList<T>::get(int theIndex) const {
	checkIndex(theIndex);
	LinkNode < T > *currentNode = firstNode;
	for (int i = 0; i < theIndex; i++) {
		currentNode = currentNode->next;
	}
	return currentNode->element;
}
template<class T>
int LinkList<T>::indexOf(const T& theIndex) const {
	LinkNode < T > *currentNode = firstNode;
	int index = 0;
	while (currentNode != NULL && currentNode->element != theIndex) {
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode == NULL)
		return -1;
	else
		return index;
}
template<class T>
void LinkList<T>::erase(int theIndex) {
	checkIndex(theIndex);
	LinkNode < T > *deleteNode;
	if (theIndex == 0) {
		deleteNode = firstNode;
		firstNode = firstNode->next;
	} else {
		LinkNode < T > *p = firstNode;
		for (int i = 0; i < theIndex - 1; i++) {
			p = p->next;
		}
		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
}
template<class T>
void LinkList<T>::insert(int theIndex, const T& theElement) {
	if (theIndex < 0 || theIndex > listSize) {
		ostringstream s;
		s << "index= " << theIndex << " size= " << listSize;
		throw illegalIndex(s.str());
	}
	if (theIndex == 0)
		firstNode = new LinkNode<T>(theElement, firstNode);
	else {
		LinkNode < T > *p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		LinkNode < T > *node = new LinkNode<T>(theElement, p->next);
		p->next = node;
	}
	listSize++;
}
template<class T>
void LinkList<T>::output(ostream & out) const {
	for (LinkNode < T > *currentNode = firstNode; currentNode != NULL;
			currentNode = currentNode->next)
		out << currentNode->element << " ";
}
template<class T>
ostream& operator<<(ostream &out, const LinkList<T>&x) {
	x.output(out);
	return out;
}
void LinkListTest() {
	// test constructor
	linearList<double> *x = new LinkList<double>;
	LinkList<int> y, z;

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
	y.erase(0);
	cout << "Element 0 erased" << endl;
	cout << "The list is " << y << endl;

	cout << "Size of y = " << y.size() << endl;
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
	LinkList<int> w(y);
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
