/*
 * Chain.h
 *
 *  Created on: 2016Äê11ÔÂ29ÈÕ
 *      Author: tla001
 */

#ifndef INC_CHAIN_H_
#define INC_CHAIN_H_
#include "Common.h"
#include "linearList.h"
#include "LinkNode.h"

class linkedDigraph;
template<class T> class linkedWDigraph;

template<class T>
class chain: public linearList<T> {
	friend linkedDigraph;
	friend linkedWDigraph<int> ;
	friend linkedWDigraph<float> ;
	friend linkedWDigraph<double> ;
public:
	// constructor, copy constructor and destructor
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	// ADT methods
	bool empty() const {
		return listSize == 0;
	}
	int size() const {
		return listSize;
	}
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;

	// iterators to start and end of list
	class iterator;
	iterator begin() {
		return iterator(firstNode);
	}
	iterator end() {
		return iterator(NULL);
	}

	// iterator for chain
	class iterator {
	public:
		// typedefs required by C++ for a forward iterator
		typedef forward_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		// constructor
		iterator(LinkNode<T>* theNode = NULL) {
			node = theNode;
		}

		// dereferencing operators
		T& operator*() const {
			return node->element;
		}
		T* operator->() const {
			return &node->element;
		}

		// increment
		iterator& operator++()   // preincrement
		{
			node = node->next;
			return *this;
		}
		iterator operator++(int) // postincrement
				{
			iterator old = *this;
			node = node->next;
			return old;
		}

		// equality testing
		bool operator!=(const iterator right) const {
			return node != right.node;
		}
		bool operator==(const iterator right) const {
			return node == right.node;
		}
	protected:
		LinkNode<T>* node;
	};  // end of iterator class

protected:
	void checkIndex(int theIndex) const;
	// throw illegalIndex if theIndex invalid
	LinkNode<T>* firstNode;  // pointer to first node in chain
	int listSize;             // number of elements in list
};

template<class T>
chain<T>::chain(int initialCapacity) {             // Constructor.
	if (initialCapacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList) {             // Copy constructor.
	listSize = theList.listSize;

	if (listSize == 0) {             // theList is empty
		firstNode = NULL;
		return;
	}

	// non-empty list
	LinkNode<T>* sourceNode = theList.firstNode;
	// node in theList to copy from
	firstNode = new LinkNode<T>(sourceNode->element);
	// copy first element of theList
	sourceNode = sourceNode->next;
	LinkNode<T>* targetNode = firstNode;
	// current last node in *this
	while (sourceNode != NULL) {             // copy remaining elements
		targetNode->next = new LinkNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL; // end the chain
}

template<class T>
chain<T>::~chain() { // Chain destructor. Delete all nodes in chain.
	LinkNode<T> *nextNode;
	while (firstNode != NULL) { // delete firstNode
		nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class T>
void chain<T>::checkIndex(int theIndex) const { // Verify that theIndex is between 0 and listSize - 1.
	if (theIndex < 0 || theIndex >= listSize) {
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
}

template<class T>
T& chain<T>::get(int theIndex) const { // Return element whose index is theIndex.
									   // Throw illegalIndex exception if no such element.
	checkIndex(theIndex);

	// move to desired node
	LinkNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		currentNode = currentNode->next;

	return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const { // Return index of first occurrence of theElement.
												   // Return -1 if theElement not in list.

	// search the chain for theElement
	LinkNode<T>* currentNode = firstNode;
	int index = 0;  // index of currentNode
	while (currentNode != NULL && currentNode->element != theElement) {
		// move to next node
		currentNode = currentNode->next;
		index++;
	}

	// make sure we found matching element
	if (currentNode == NULL)
		return -1;
	else
		return index;
}

template<class T>
void chain<T>::erase(int theIndex) { // Delete the element whose index is theIndex.
									 // Throw illegalIndex exception if no such element.
	checkIndex(theIndex);

	// valid index, locate node with element to delete
	LinkNode<T>* deleteNode;
	if (theIndex == 0) { // remove first node from chain
		deleteNode = firstNode;
		firstNode = firstNode->next;
	} else {  // use p to get to predecessor of desired node
		LinkNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;

		deleteNode = p->next;
		p->next = p->next->next; // remove deleteNode from chain
	}
	listSize--;
	delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement) { // Insert theElement so that its index is theIndex.
	if (theIndex < 0 || theIndex > listSize) { // invalid index
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (theIndex == 0)
		// insert at front
		firstNode = new LinkNode<T>(theElement, firstNode);
	else {  // find predecessor of new element
		LinkNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;

		// insert after p
		p->next = new LinkNode<T>(theElement, p->next);
	}
	listSize++;
}

template<class T>
void chain<T>::output(ostream& out) const { // Put the list into the stream out.
	for (LinkNode<T>* currentNode = firstNode; currentNode != NULL;
			currentNode = currentNode->next)
		out << currentNode->element << "  ";
}

// overload <<
template<class T>
ostream& operator<<(ostream& out, const chain<T>& x) {
	x.output(out);
	return out;
}
#endif /* INC_CHAIN_H_ */
