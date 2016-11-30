/*
 * WinnerTree.h
 *
 *  Created on: 2016Äê11ÔÂ26ÈÕ
 *      Author: tla001
 */

#ifndef INC_WINNERTREE_H_
#define INC_WINNERTREE_H_
#include "Common.h"
template<class T>
class winnerTree {
public:
	virtual ~winnerTree() {
	}
	virtual void initialize(T *thePlayer, int theNumberOfPlayers) = 0;
	// create winner tree with thePlayer[1:numberOfPlayers]
	virtual int winner() const = 0;
	// return index of winner
	virtual void rePlay(int thePLayer) = 0;
	// replay matches following a change in thePLayer
};

#endif /* INC_WINNERTREE_H_ */
