/*
 * Matrix.cpp
 *
 *  Created on: 2016��11��14��
 *      Author: tla001
 */

#include "Matrix.h"

void MatrxTest() {
	try {
		Matrix<int> x(3, 2), y, z;
		int i, j;
		for (i = 1; i <= 3; i++)
			for (j = 1; j <= 2; j++)
				x(i, j) = 2 * i + j;
		cout << "Initialized x(i,j) = 2*i + j" << endl;
		cout << "x(3,1) = " << x(3, 1) << endl;
		cout << "x is" << endl;
		;
		cout << x << endl;

		y = x;
		cout << "Assigned y = x" << endl;
		cout << "y is" << endl;
		cout << y << endl;

		x += 2;
		cout << "x incremented by 2 is" << endl;
		cout << x << endl;

		z = y + x;
		cout << "y + x is" << endl;
		cout << z << endl;

		cout << "-(y + x) is" << endl;
		cout << -z << endl;

		Matrix<int> w(2, 3);
		for (i = 1; i <= 2; i++)
			for (j = 1; j <= 3; j++)
				w(i, j) = i + j;
		cout << "Initialized w(i,j) = i + j" << endl;
		cout << "w is" << endl;
		cout << w << endl;

		z = y * w;
		cout << "y * w is" << endl;
		cout << z << endl;

		Matrix<int> x1(3, 2), y1;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 2; j++)
				x1(i, j) = 2 * i + j;
		cout << "Initialized x1(i,j) = 2*i + j" << endl;
		cout << "x1 is" << endl;
		;
		cout << x1 << endl;

		x1.transpose(y1);
		cout << "Assigned y1 = x.transpose" << endl;
		cout << "y1 is" << endl;
		cout << y1 << endl;
	} catch (...) {
		cerr << "An exception has occurred" << endl;
	}
}

