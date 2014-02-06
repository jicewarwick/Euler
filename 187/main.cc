/*
 * A composite is a number containing at least two prime factors. For example,
 * 15 = 3 × 5; 9 = 3 × 3; 12 = 2 × 2 × 3.
 *
 * There are ten composites below thirty containing precisely two, not
 * necessarily distinct, prime factors: 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.
 *
 * How many composite integers, n < 10^8, have precisely two, not necessarily
 * distinct, prime factors?
 */

#include <iostream>
#include <vector>
#include "numberTheory.h"

using namespace std;

void fillPrime(vector<long long>&, long long);

int main(int argc, const char *argv[])
{
	long long numSemiPrime = 0;
	vector<long long> prime;
	const long long MAX = 1e8;
	fillPrime(prime, MAX / 2);
	long long size = prime.size();

	for (vector<long long>::iterator it = prime.begin(); it != prime.end(); it++) {
		for (vector<long long>::iterator jt = prime.begin() size - size / *it; jt != prime.end(); jt++) {
			//cout << *it << '\t' << *jt << endl;
			if (*it * *jt > MAX) {
				numSemiPrime += 
				//cout << *it << '\t' << *jt << endl;
			} else {
				break;
			}
		}
	}
	
	cout << "The number of Semiprime below " << MAX << " is " << numSemiPrime << endl;

	return 0;
}

void fillPrime(vector<long long> &prime, long long n){
	for (long long i = 2; i <= n; i++) {
		if (isPrime(i)) {
			prime.push_back(i);
			//cout << i << '\t';
		}
	}
	//cout << endl;
}

