/*
 * LinkList.h
 *
 *  Created on: 2016Äê11ÔÂ10ÈÕ
 *      Author: tla001
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <linearList.h>
#include <LinkNode.h>

template<class T>
class LinkList: public linearList<T> {
public:
	LinkList(int initialCapacity = 10);
	LinkList(const LinkList<T>&);
	~LinkList();

	bool empty() const {
		return listSize == 0;
	}
	int size() const {
		return listSize;
	}
	T& get(int theIndex) const;
	int indexOf(const T& theIndex) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream & out) const;

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
	LinkNode<T>* firstNode;
	int listSize;
};
void LinkListTest();
#endif /* LINKLIST_H_ */
