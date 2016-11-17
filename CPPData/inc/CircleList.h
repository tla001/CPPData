/*
 * CircleList.h
 *
 *  Created on: 2016Äê11ÔÂ11ÈÕ
 *      Author: tla001
 */

#ifndef CIRCLELIST_H_
#define CIRCLELIST_H_

#include "Common.h"
#include <LinkNode.h>

template<class T>
class CircleList {
public:
public:
	// constructor
	CircleList();

	// some methods
	int size() const {
		return listSize;
	}
	int indexOf(const T& theElement) const;
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;

protected:
	void checkIndex(int theIndex) const;
	// throw illegalIndex if theIndex invalid
	LinkNode<T>* headerNode;  // pointer to header node
	int listSize;              // number of elements in list
};
void CircleListTest();

template<class T>
CircleList<T>::CircleList() {            // Constructor.
	headerNode = new LinkNode<T>();
	headerNode->next = headerNode;
	listSize = 0;
}

template<class T>
void CircleList<T>::checkIndex(int theIndex) const { // Verify that theIndex is between 0 and listSize - 1.
	if (theIndex < 0 || theIndex >= listSize) {
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

}

template<class T>
int CircleList<T>::indexOf(const T& theElement) const { // Return index of first occurrence of theElement.
														// Return -1 if theElement not in list.

	// Put theElement in header node
	headerNode->element = theElement;

	// search the chain for theElement
	LinkNode<T> *currentNode = headerNode->next;
	int index = 0;  // index of currentNode
	while (currentNode->element != theElement) {
		// move to next node
		currentNode = currentNode->next;
		index++;
	}

	// make sure we found matching element
	if (currentNode == headerNode)
		return -1;
	else
		return index;
}

template<class T>
void CircleList<T>::insert(int theIndex, const T& theElement) { // Insert theElement so that its index is theIndex.
	if (theIndex < 0 || theIndex > listSize) {  // invalid index
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

	// find predecessor of new element
	LinkNode<T> *p = headerNode;
	for (int i = 0; i < theIndex; i++)
		p = p->next;

	// insert after p
	p->next = new LinkNode<T>(theElement, p->next);

	listSize++;
}

template<class T>
void CircleList<T>::output(ostream& out) const { // Put the list into the stream out.
	for (LinkNode<T> *currentNode = headerNode->next; currentNode != headerNode;
			currentNode = currentNode->next)
		out << currentNode->element << "  ";
}

// overload <<
template<class T>
ostream& operator<<(ostream& out, const CircleList<T>& x) {
	x.output(out);
	return out;
}

#endif /* CIRCLELIST_H_ */
