/*
 * Edge.h
 *
 *  Created on: 2016Äê11ÔÂ29ÈÕ
 *      Author: tla001
 */

#ifndef INC_GRAPHCOMMON_H_
#define INC_GRAPHCOMMON_H_
#include "Common.h"
#include "Chain.h"
#include "LinkNode.h"
template<class T>
class edge {
public:
	virtual ~edge() {
	}
	;
	virtual int vertex1() const = 0;
	virtual int vertex2() const = 0;
	virtual T weight() const = 0;
};

template<class T>
class vertexIterator {
public:
	virtual ~vertexIterator() {
	}
	virtual int next() = 0;
	virtual int next(T&) = 0;
};

struct binNode {
	int left, right;  // pointers to left and right nodes
};

template<class T>
class weightedEdge: public edge<T> {
public:
	weightedEdge() {
	}
	;
	weightedEdge(int theV1, int theV2, T theW) {
		v1 = theV1;
		v2 = theV2;
		w = theW;
	}
	~weightedEdge() {
	}
	;
	int vertex1() const {
		return v1;
	}
	int vertex2() const {
		return v2;
	}
	T weight() const {
		return w;
	}
	operator T() const {
		return w;
	}
	void output(ostream& out) const {  // Put the edge into the stream out.
		out << "(" << v1 << ", " << v2 << ", " << w << ")";
	}

private:
	int v1, v2;
	T w;
};

// overload <<
template<class T>
ostream& operator<<(ostream& out, const weightedEdge<T>& x) {
	x.output(out);
	return out;
}

template<class T>
class graphChain: public chain<T> {
public:
	T* eraseElement(int theVertex) { // Delete node with element == theVertex. Return pointer to
									 // deleted element. Return NULL if no matching element.
		LinkNode<T> *current = chain < T > ::firstNode, *trail = NULL; // one behind current

		// search for match
		while (current != NULL && current->element != theVertex) {
			trail = current;
			current = current->next;
		}

		if (current == NULL) // no match
			return NULL;

		// match found in node current
		T* theElement = &current->element; // save matching element

		// remove current from chain
		if (trail != NULL)
			trail->next = current->next;
		else
			chain < T > ::firstNode = current->next; // current is first node

		delete current;
		chain < T > ::listSize--;
		return theElement;
	}
};

#endif /* INC_GRAPHCOMMON_H_ */
