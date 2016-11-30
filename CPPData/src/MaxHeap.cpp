/*
 * MaxHeap.cpp
 *
 *  Created on: 2016Äê11ÔÂ22ÈÕ
 *      Author: tla001
 */

#include "MaxHeap.h"

void MaxHeapTest() {
	// test constructor and push
	MaxHeap<int> h(4);
	h.push(10);
	h.push(20);
	h.push(5);

	cout << "Heap size is " << h.size() << endl;
	cout << "Elements in array order are" << endl;
	cout << h << endl;

	h.push(15);
	h.push(30);

	cout << "Heap size is " << h.size() << endl;
	cout << "Elements in array order are" << endl;
	cout << h << endl;

	// test top and pop
	cout << "The max element is " << h.top() << endl;
	h.pop();
	cout << "The max element is " << h.top() << endl;
	h.pop();
	cout << "The max element is " << h.top() << endl;
	h.pop();
	cout << "Heap size is " << h.size() << endl;
	cout << "Elements in array order are" << endl;
	cout << h << endl;

	// test initialize
	int z[10];
	for (int i = 1; i < 10; i++)
		z[i] = i;
	h.initialize(z, 9);
	cout << "Elements in array order are" << endl;
	cout << h << endl;
}
