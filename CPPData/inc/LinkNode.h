/*
 * LinkNode.h
 *
 *  Created on: 2016��11��11��
 *      Author: tla001
 */

#ifndef LINKNODE_H_
#define LINKNODE_H_

template<class T>
struct LinkNode {
	T element;
	LinkNode<T>*next;

	LinkNode() {
	}
	LinkNode(const T& element) {
		this->element = element;
	}
	LinkNode(const T&element, LinkNode<T>*next) {
		this->element = element;
		this->next = next;
	}
};
#endif /* LINKNODE_H_ */
