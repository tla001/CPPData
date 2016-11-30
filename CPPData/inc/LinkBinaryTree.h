/*
 * LinkBinaryTree.h
 *
 *  Created on: 2016Äê11ÔÂ20ÈÕ
 *      Author: tla001
 */

#ifndef LINKBINARYTREE_H_
#define LINKBINARYTREE_H_
#include "Common.h"
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "Booster.h"
#include "ArrayQueue.h"
#include <typeinfo>

void LinkBinaryTreeTest();

template<class E>
class LinkBinaryTree: public binaryTree<binaryTreeNode<E> > {
public:
	LinkBinaryTree() {
		root = NULL;
		treeSize = 0;
	}
	~LinkBinaryTree() {
		erase();
	}
	;
	bool empty() const {
		return treeSize == 0;
	}
	int size() const {
		return treeSize;
	}
	E* rootElement() const;
	void makeTree(const E& element, LinkBinaryTree<E>&, LinkBinaryTree<E>&);
	LinkBinaryTree<E>& removeLeftSubtree();
	LinkBinaryTree<E>& removeRightSubtree();
	void preOrder(void (*theVisit)(binaryTreeNode<E>*)) {
		visit = theVisit;
		//cout << typeid(theVisit).name() << endl;
		preOrder(root);
	}
	void inOrder(void (*theVisit)(binaryTreeNode<E>*)) {
		visit = theVisit;
		inOrder(root);
	}
	void postOrder(void (*theVisit)(binaryTreeNode<E>*)) {
		visit = theVisit;
		postOrder(root);
	}
	void levelOrder(void (*)(binaryTreeNode<E> *));
	void preOrderOutput() {
		preOrder(output);
		cout << endl;
	}
	void inOrderOutput() {
		inOrder(output);
		cout << endl;
	}
	void postOrderOutput() {
		postOrder(output);
		cout << endl;
	}
	void levelOrderOutput() {
		levelOrder(output);
		cout << endl;
	}
	void erase() {
		postOrder(dispose);
		root = NULL;
		treeSize = 0;
	}
	int height() const {
		return height(root);
	}
protected:
	binaryTreeNode<E> *root;                // pointer to root
	int treeSize;                           // number of nodes in tree
	static void (*visit)(binaryTreeNode<E>*);      // visit function
	static int count;         // used to count nodes in a subtree
	static void preOrder(binaryTreeNode<E> *t);
	static void inOrder(binaryTreeNode<E> *t);
	static void postOrder(binaryTreeNode<E> *t);
	static void countNodes(binaryTreeNode<E> *t) {
		visit = addToCount;
		count = 0;
		preOrder(t);
	}
	static void dispose(binaryTreeNode<E> *t) {
		delete t;
	}
	static void output(binaryTreeNode<E> *t) {
		cout << t->element << ' ';
	}
	static void addToCount(binaryTreeNode<E> *t) {
		count++;
	}
	static int height(binaryTreeNode<E> *t);
};

// the following should work but gives an internal compiler error
// template <class E> void (*LinkBinaryTree<E>::visit)(binaryTreeNode<E>*);
// so the explicit declarations that follow are used for our purpose instead
//template<> void (*LinkBinaryTree<int>::visit)(binaryTreeNode<int>*);
//void (*LinkBinaryTree<booster>::visit)(binaryTreeNode<booster>*);
//void (*LinkBinaryTree<pair<int, int> >::visit)(
//		binaryTreeNode<pair<int, int> >*);
//void (*LinkBinaryTree<pair<const int, char> >::visit)(
//		binaryTreeNode<pair<const int, char> >*);
//void (*LinkBinaryTree<pair<const int, int> >::visit)(
//		binaryTreeNode<pair<const int, int> >*);
template<class E> void (*LinkBinaryTree<E>::visit)(binaryTreeNode<E>*);

template<class E>
E* LinkBinaryTree<E>::rootElement() const { // Return NULL if no root. Otherwise, return pointer to root element.
	if (treeSize == 0)
		return NULL;  // no root
	else
		return &root->element;
}

template<class E>
void LinkBinaryTree<E>::makeTree(const E& element, LinkBinaryTree<E>& left,
		LinkBinaryTree<E>& right) { // Combine left, right, and element to make new tree.
									// left, right, and this must be different trees.
									// create combined tree
	root = new binaryTreeNode<E>(element, left.root, right.root);
	treeSize = left.treeSize + right.treeSize + 1;

	// deny access from trees left and right
	left.root = right.root = NULL;
	left.treeSize = right.treeSize = 0;
}

template<class E>
LinkBinaryTree<E>& LinkBinaryTree<E>::removeLeftSubtree() { // Remove and return the left subtree.
// check if empty
	if (treeSize == 0)
		throw emptyTree();

	// detach left subtree and save in leftSubtree
	LinkBinaryTree<E> leftSubtree;
	leftSubtree.root = root->leftChild;
	count = 0;
	leftSubtree.treeSize = countNodes(leftSubtree.root);
	root->leftChild = NULL;
	treeSize -= leftSubtree.treeSize;

	return leftSubtree;
}

template<class E>
LinkBinaryTree<E>& LinkBinaryTree<E>::removeRightSubtree() { // Remove and return the right subtree.
// check if empty
	if (treeSize == 0)
		throw emptyTree();

	// detach right subtree and save in rightSubtree
	LinkBinaryTree<E> rightSubtree;
	rightSubtree.root = root->rightChild;
	count = 0;
	rightSubtree.treeSize = countNodes(rightSubtree.root);
	root->rightChild = NULL;
	treeSize -= rightSubtree.treeSize;

	return rightSubtree;
}

template<class E>
void LinkBinaryTree<E>::preOrder(binaryTreeNode<E> *t) { // Preorder traversal.
	if (t != NULL) {
		LinkBinaryTree<E>::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}

template<class E>
void LinkBinaryTree<E>::inOrder(binaryTreeNode<E> *t) { // Inorder traversal.
	if (t != NULL) {
		inOrder(t->leftChild);
		LinkBinaryTree<E>::visit(t);
		inOrder(t->rightChild);
	}
}

template<class E>
void LinkBinaryTree<E>::postOrder(binaryTreeNode<E> *t) { // Postorder traversal.
	if (t != NULL) {
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		LinkBinaryTree<E>::visit(t);
	}
}

template<class E>
void LinkBinaryTree<E>::levelOrder(void (*theVisit)(binaryTreeNode<E> *)) { // Level-order traversal.
	ArrayQueue<binaryTreeNode<E>*> q;
	binaryTreeNode<E> *t = root;
	while (t != NULL) {
		theVisit(t);  // visit t

		// put t's children on queue
		if (t->leftChild != NULL)
			q.push(t->leftChild);
		if (t->rightChild != NULL)
			q.push(t->rightChild);

		// get next node to visit
		try {
			t = q.front();
		} catch (queueEmpty) {
			return;
		}
		q.pop();
	}
}

template<class E>
int LinkBinaryTree<E>::height(binaryTreeNode<E> *t) { // Return height of tree rooted at *t.
	if (t == NULL)
		return 0;                    // empty tree
	int hl = height(t->leftChild);  // height of left
	int hr = height(t->rightChild); // height of right
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

#endif /* LINKBINARYTREE_H_ */
