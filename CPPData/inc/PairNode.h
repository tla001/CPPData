/*
 * PairNode.h
 *
 *  Created on: 2016Äê11ÔÂ19ÈÕ
 *      Author: tla001
 */

#ifndef INC_PAIRNODE_H_
#define INC_PAIRNODE_H_
#include "Common.h"

template<class K, class E>
struct pairNode {
	typedef pair<const K, E> pairType;
	pairType element;
	pairNode<K, E> *next;

	pairNode(const pairType& thePair) :
			element(thePair) {
	}
	pairNode(const pairType& thePair, pairNode<K, E>* theNext) :
			element(thePair) {
		next = theNext;
	}
};

#endif /* INC_PAIRNODE_H_ */
