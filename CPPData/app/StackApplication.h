/*
 * StackApplication.h
 *
 *  Created on: 2016年11月18日
 *      Author: tla001
 *
 *      栈应用
 */
#include "Common.h"
#include "ArrayStack.h"
/*
 * 括号匹配
 * 从左向右扫描，左括号入栈，右括号依次与栈顶元素匹配
 */
void printMatchedPairs(string expr) {
	ArrayStack<int> s;
	int length = (int) expr.size();
	for (int i = 0; i < length; i++) {
		if (expr.at(i) == '(')
			s.push(i);
		else if (expr.at(i) == ')')
			try {
				cout << s.top() << " " << i << endl;
				s.pop();
			} catch (stackEmpty) {
				cout << "NO Match for right " << " at " << i << endl;
			}
		while (!s.empty()) {
			cout << "NO match for left at" << s.top() << endl;
			s.pop();
		}
	}
}
/*
 * hanoi
 */
// global variable, tower[1:3] are the three towers
ArrayStack<int> tower[4];
void moveAndShow(int n, int x, int y, int z);
void towersOfHanoi(int n) { // Preprocessor for moveAndShow.
	for (int d = n; d > 0; d--) // initialize
		tower[1].push(d); // add disk d to tower 1

	// move n disks from tower 1 to 3 using 2 as
	// intermediate tower
	moveAndShow(n, 1, 2, 3);
}

void moveAndShow(int n, int x, int y, int z) { // Move the top n disks from tower x to tower y showing states.
											   // Use tower z for intermediate storage.
	if (n > 0) {
		moveAndShow(n - 1, x, z, y);
		int d = tower[x].top();   // move a disk from top of
		tower[x].pop();           // tower x to top of
		tower[y].push(d);         // tower y
		// showState();              // show state of 3 towers
		// substitute showState code for test run
		cout << "Move disk " << d << " from tower " << x << " to top of tower "
				<< y << endl;
		moveAndShow(n - 1, z, y, x);
	}
}

void hanoiTest(void) {
	cout << "Moves for a three disk problem are" << endl;
	towersOfHanoi(3);
}
