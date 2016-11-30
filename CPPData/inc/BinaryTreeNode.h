/*
 * BinaryTreeNode.h
 *
 *  Created on: 2016Äê11ÔÂ20ÈÕ
 *      Author: tla001
 */

#ifndef INC_BINARYTREENODE_H_
#define INC_BINARYTREENODE_H_
#include "Common.h"
template<class T>
struct binaryTreeNode {
	T element;
	binaryTreeNode<T> *leftChild,   // left subtree
			*rightChild;  // right subtree

	binaryTreeNode() {
		leftChild = rightChild = NULL;
	}
	binaryTreeNode(const T& theElement) :
			element(theElement) {
		leftChild = rightChild = NULL;
	}
	binaryTreeNode(const T& theElement, binaryTreeNode *theLeftChild,
			binaryTreeNode *theRightChild) :
			element(theElement) {
		leftChild = theLeftChild;
		rightChild = theRightChild;
	}
};

#endif /* INC_BINARYTREENODE_H_ */
