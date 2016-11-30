/*
 * Booster.h
 *
 *  Created on: 2016Äê11ÔÂ20ÈÕ
 *      Author: tla001
 */

#ifndef INC_BOOSTER_H_
#define INC_BOOSTER_H_

#include "Common.h"
struct booster {
	int degradeToLeaf,           // degradation to leaf
			degradeFromParent;       // degradation from parent
	bool boosterHere;            // true iff booster here

	void output(ostream& out) const {
		out << boosterHere << ' ' << degradeToLeaf << ' ' << degradeFromParent
				<< ' ';
	}
};

// overload <<
inline ostream& operator<<(ostream& out, booster x) {
	x.output(out);
	return out;
}

#endif /* INC_BOOSTER_H_ */
