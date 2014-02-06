/*© Copyright 2013 Ce Ji. All Rights Reserved.
 * 2013-12-23
 * 
 * In response to problem 25 of Project Euler
 *
 * finding the first term of Fibonacci sequence that contains
 * 1000 digits
 *
 * The question is not well implemented as the question involves
 * a enormous large number and purely numerical approach is appreciated
 * unless an arbitrary-precision arithmetic library is used.
 *
 */


#include <iostream>
#include <cmath>
#include "Fibonacci.h"

using namespace std;


int main(int argc, const char *argv[])
{
	Fibonacci x = Fibonacci();
	cout << x.val(55)<< endl;
	cout << x.smallest( pow(10, 999) ) << endl;
	return 0;
}
