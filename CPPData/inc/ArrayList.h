/*
 * ArrayList.h
 *
 *  Created on: 2016Äê11ÔÂ7ÈÕ
 *      Author: tla001
 */

#ifndef INC_ARRAYLIST_H_
#define INC_ARRAYLIST_H_

#include <linearList.h>

template<class T>
class ArrayList: public linearList<T> {
public:
	ArrayList(int initialCapacity = 10);
	ArrayList(const ArrayList<T>&);
	~ArrayList() {
		delete[] element;
	}

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

	int capacity() const {
		return arrayLength;
	}
	// iterators to start and end of list
	class iterator;
	iterator begin() {
		return iterator(element);
	}
	iterator end() {
		return iterator(element + listSize);
	}

	// iterator for arrayList
	class iterator {
	public:
		// typedefs required by C++ for a bidirectional iterator
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		// constructor
		iterator(T* thePosition = 0) {
			position = thePosition;
		}

		// dereferencing operators
		T& operator*() const {
			return *position;
		}
		T* operator->() const {
			return &*position;
		}

		// increment
		iterator& operator++()   // preincrement
		{
			++position;
			return *this;
		}
		iterator operator++(int) // postincrement
				{
			iterator old = *this;
			++position;
			return old;
		}

		// decrement
		iterator& operator--()   // predecrement
		{
			--position;
			return *this;
		}
		iterator operator--(int) // postdecrement
				{
			iterator old = *this;
			--position;
			return old;
		}

		// equality testing
		bool operator!=(const iterator right) const {
			return position != right.position;
		}
		bool operator==(const iterator right) const {
			return position == right.position;
		}
	protected:
		T* position;
	};  // end of iterator class
protected:
	void checkIndex(int theIndex) const;
	T* element;
	int arrayLength;
	int listSize;
};
void ArrayListTest();
#endif /* INC_ARRAYLIST_H_ */
