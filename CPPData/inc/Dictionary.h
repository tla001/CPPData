/*
 * Dictionary.h
 *
 *  Created on: 2016Äê11ÔÂ19ÈÕ
 *      Author: tla001
 */

#ifndef INC_DICTIONARY_H_
#define INC_DICTIONARY_H_

#include "Common.h"
template<class K, class E>
class Dictionary {
public:
	virtual ~Dictionary() {
	}
	virtual bool empty() const = 0;
	// return true iff dictionary is empty
	virtual int size() const = 0;
	// return number of pairs in dictionary
	virtual pair<const K, E>* find(const K&) const = 0;
	// return pointer to matching pair
	virtual void erase(const K&) = 0;
	// remove matching pair
	virtual void insert(const pair<const K, E>&) = 0;
	// insert a (key, value) pair into the dictionary
};

#endif /* INC_DICTIONARY_H_ */
