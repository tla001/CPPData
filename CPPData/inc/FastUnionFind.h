/*
 * FastUnionFind.h
 *
 *  Created on: 2016Äê11ÔÂ29ÈÕ
 *      Author: tla001
 */

#ifndef INC_FASTUNIONFIND_H_
#define INC_FASTUNIONFIND_H_

#include "Common.h"

struct unionFindNode {
	int parent;  // if true then tree weight
				 // otherwise pointer to parent in tree
	bool root;   // true iff root

	unionFindNode() {
		parent = 1;
		root = true;
	}
};

class fastUnionFind {
public:
	fastUnionFind(int numberOfElements) { // Initialize numberOfElements trees, 1 element per set/class/tree.
		node = new unionFindNode[numberOfElements + 1];
	}

	void unite(int rootA, int rootB) { // Combine trees with different roots rootA and rootB.
									   // Use the weighting rule.
		if (node[rootA].parent < node[rootB].parent) { // rootA becomes subtree of rootB
			node[rootB].parent += node[rootA].parent;
			node[rootA].root = false;
			node[rootA].parent = rootB;
		} else {       // rootB becomes subtree of rootA
			node[rootA].parent += node[rootB].parent;
			node[rootB].root = false;
			node[rootB].parent = rootA;
		}
	}

	int find(int theElement) {     // Return root of tree containing theElement.
								   // Compact path from theElement to root.

		// theRoot will eventually be the root of the tree
		int theRoot = theElement;
		while (!node[theRoot].root)
			theRoot = node[theRoot].parent;

		// compact pathe from theElement to theRoot
		int currentNode = theElement;  // start at theElement
		while (currentNode != theRoot) {
			int parentNode = node[currentNode].parent;
			node[currentNode].parent = theRoot;  // move to level 2
			currentNode = parentNode;            // moves to old parent 
		}

		return theRoot;
	}

protected:
	unionFindNode *node;
};

#endif /* INC_FASTUNIONFIND_H_ */
