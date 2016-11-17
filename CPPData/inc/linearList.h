/*
 * linearList.h
 *
 *  Created on: 2016Äê11ÔÂ7ÈÕ
 *      Author: tla001
 *      abstract class for linerList
 */

#ifndef INC_LINEARLIST_H_
#define INC_LINEARLIST_H_
#include "Common.h"

template<class T>
class linearList {
public:
	virtual ~linearList() {
	}
	;
	virtual bool empty() const=0;
	virtual int size() const=0;
	virtual T& get(int theIndex) const=0;
	virtual int indexOf(const T& theElement) const=0;
	virtual void erase(int theIndex)=0;
	virtual void insert(int theIndex, const T& theElement)=0;
	virtual void output(ostream& out) const=0;
};

#endif /* INC_LINEARLIST_H_ */
