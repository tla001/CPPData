/*
 * IndexedBSTree.h
 *
 *  Created on: 2016Äê11ÔÂ29ÈÕ
 *      Author: tla001
 */

#ifndef INC_INDEXEDBSTREE_H_
#define INC_INDEXEDBSTREE_H_

#include "BsTree.h"

template<class K, class E>
class indexedBSTree: public bsTree<K, E> {
public:
	virtual pair<const K, E>* get(int) const = 0;
	// return pointer to pair with given index
	virtual void delete(int) = 0;
};
#endif /* INC_INDEXEDBSTREE_H_ */
