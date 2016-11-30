/*
 * BsTree.h
 *
 *  Created on: 2016��11��29��
 *      Author: tla001
 */

#ifndef INC_BSTREE_H_
#define INC_BSTREE_H_

#include "Dictionary.h"

template<class K, class E>
class bsTree: public Dictionary<K, E> {
public:
	virtual void ascend() = 0;
	// output in ascending order of key
};

#endif /* INC_BSTREE_H_ */
