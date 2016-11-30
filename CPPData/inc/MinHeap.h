/*
 * MinHeap.h
 *
 *  Created on: 2016Äê11ÔÂ29ÈÕ
 *      Author: tla001
 */

#ifndef INC_MINHEAP_H_
#define INC_MINHEAP_H_

#include "Common.h"
#include <sstream>
#include <algorithm>

template<class T>
class minPriorityQueue {
public:
	virtual ~minPriorityQueue() {
	}
	virtual bool empty() const = 0;
	// return true iff queue is empty
	virtual int size() const = 0;
	// return number of elements in queue
	virtual const T& top() = 0;
	// return reference to the min element
	virtual void pop() = 0;
	// remove the top element
	virtual void push(const T& theElement) = 0;
	// add theElement to the queue
};

template<class T>
class minHeap: public minPriorityQueue<T> {
public:
	minHeap(int initialCapacity = 10);
	~minHeap() {
		delete[] heap;
	}
	bool empty() const {
		return heapSize == 0;
	}
	int size() const {
		return heapSize;
	}
	const T& top() { // return min element
		if (heapSize == 0)
			throw queueEmpty();
		return heap[1];
	}
	void pop();
	void push(const T&);
	void initialize(T *, int);
	void deactivateArray() {
		heap = NULL;
		arrayLength = heapSize = 0;
	}
	void output(ostream& out) const;
private:
	int heapSize;       // number of elements in queue
	int arrayLength;    // queue capacity + 1
	T *heap;            // element array
};

template<class T>
minHeap<T>::minHeap(int initialCapacity) {            // Constructor.
	if (initialCapacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity + 1;
	heap = new T[arrayLength];
	heapSize = 0;
}

template<class T>
void minHeap<T>::push(const T& theElement) {          // Add theElement to heap.

	// increase array length if necessary
	if (heapSize == arrayLength - 1) {            // double array length
		changeLength1D(heap, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	// find place for theElement
	// currentNode starts at new leaf and moves up tree
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] > theElement) {
		// cannot put theElement in heap[currentNode]
		heap[currentNode] = heap[currentNode / 2]; // move element down
		currentNode /= 2;                          // move to parent
	}

	heap[currentNode] = theElement;
}

template<class T>
void minHeap<T>::pop() {                          // Remove max element.
// if heap is empty return null
	if (heapSize == 0)   // heap empty
		throw queueEmpty();

	// Delete min element
	heap[1].~T();

	// Remove last element and reheapify
	T lastElement = heap[heapSize--];

	// find place for lastElement starting at root
	int currentNode = 1, child = 2;     // child of currentNode
	while (child <= heapSize) {
		// heap[child] should be smaller child of currentNode
		if (child < heapSize && heap[child] > heap[child + 1])
			child++;

		// can we put lastElement in heap[currentNode]?
		if (lastElement <= heap[child])
			break;   // yes

		// no
		heap[currentNode] = heap[child]; // move child up
		currentNode = child;             // move down a level
		child *= 2;
	}
	heap[currentNode] = lastElement;
}

template<class T>
void minHeap<T>::initialize(T *theHeap, int theSize) { // Initialize max heap to element array theHeap[1:theSize].
	delete[] heap;
	heap = theHeap;
	heapSize = theSize;

	// heapify
	for (int root = heapSize / 2; root >= 1; root--) {
		T rootElement = heap[root];

		// find place to put rootElement
		int child = 2 * root; // parent of child is target
							  // location for rootElement
		while (child <= heapSize) {
			// heap[child] should be smaller sibling
			if (child < heapSize && heap[child] > heap[child + 1])
				child++;

			// can we put rootElement in heap[child/2]?
			if (rootElement <= heap[child])
				break;  // yes

			// no
			heap[child / 2] = heap[child]; // move child up
			child *= 2;                    // move down a level
		}
		heap[child / 2] = rootElement;
	}
}

template<class T>
void minHeap<T>::output(ostream& out) const { // Put the array into the stream out.
	copy(heap + 1, heap + heapSize + 1, ostream_iterator<T>(cout, "  "));
}

// overload <<
template<class T>
ostream& operator<<(ostream& out, const minHeap<T>& x) {
	x.output(out);
	return out;
}

#endif /* INC_MINHEAP_H_ */
