/*
 * Goldbach's other conjecture
 *
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include <iostream>
#include <cmath>
#include "numberTheory.h"

using namespace std;

int first_failure_of_Goldbach_conjecture(void);

bool Goldbach_conjecture_test(int);

int main(int argc, const char *argv[])
{
	//cout << "odd?" << '\t' << isOdd(3) << endl;
	//cout << "even?" << '\t' << isEven(3) << endl;
	cout << "The Goldbach conjecture fails at number:" << '\t' << first_failure_of_Goldbach_conjecture() << endl;
	return 0;
}

bool Goldbach_conjecture_test(int n){
	bool ret = true;
	if (isEven(n)) {
		cout << "The input number" << n << "is Even" << endl;
		ret = false;
	} else if (isPrime(n)) {
		cout << "The input number" << n << "is Prime" << endl;
		ret = false;
	} else {
		for (int i = 1; i < sqrt(n / 2.0); i++) {
			bool tmp = true;
			tmp = isPrime(n - 2 * i * i);
			if (tmp) {
				break;
			}
		}
	}
	return ret;
}

int first_failure_of_Goldbach_conjecture(void) {
	int i = 9;
	int ret = 0;
	bool tmp = false;	// indicator for whether loop number fails the conjecture

	while ( i < 100000000) {
		tmp = false;	// initialise for each number
		if (! isPrime(i)) {
			for (int j = 1; j < sqrt(i/2); j++) {
				if ( isPrime(i - 2 * j * j) ) {
					tmp = true;
					break;
				}
			}
			if (tmp == false) {
				ret = i;
				break;
			}
		}		
		i += 2;
	}
	return ret;
}
