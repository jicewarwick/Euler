/*
 * A composite is a number containing at least two prime factors. For example,
 * 15 = 3 × 5; 9 = 3 × 3; 12 = 2 × 2 × 3.
 *
 * There are ten composites below thirty containing precisely two, not
 * necessarily distinct, prime factors: 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.
 *
 * How many composite integers, n < 10^8, have precisely two, not necessarily
 * distinct, prime factors?
 *
 * Firstly, I generate a vector of primes up to MAX / 2, then, searching the
 * minimum number for each i in the prime vector such that the product is less
 * than MAX. using the offsetting difference to infer the number of Semiprime
 * given i.
 *
 * A little tweak is used to decrease the computational time. middle is created
 * as a reference point as i do not need to exceeds middle and j cannot be below
 * that value.
 *
 * Although this works, it takes ridiculously long (about 2'41"). A much faster
 * method such as sieving can be used. Several method can be found in the forum.
 *
 */

#include <iostream>
#include <vector>
#include "numberTheory.h"

using namespace std;

long long fillPrime(vector<long long>&, long long);

int main(int argc, const char *argv[])
{
	vector<long long> prime;
	const long long MAX = 1e8;
	long long middle;
	middle = fillPrime(prime, MAX / 2);
	long long size = prime.size();
	long long numSemiPrime = size;
	cout << "The length of all prime under " << MAX/2 << " is " << size << endl;
	cout << "The middle reference point: " << middle << endl;

	for (vector<long long>::iterator it = prime.begin() + 1; it != prime.begin() + middle; it++) {
		for (vector<long long>::iterator jt = prime.begin() + middle - 1; jt != prime.end(); jt++) {
			if (*it * *jt > MAX) {
				numSemiPrime += jt - it;
				break;
			}
		}
	}
	
	cout << "The number of Semiprime below " << MAX << " is " << numSemiPrime << endl;

	return 0;
}

long long fillPrime(vector<long long> &prime, long long n){
	long long middle = sqrt(2 * n);
	for (long long i = 2; i <= middle; i++) {
		if (isPrime(i)) {
			prime.push_back(i);
		}
	}
	long long ret = prime.size();
	for (long long i = middle + 1; i <= n; i++) {
		if (isPrime(i)) {
			prime.push_back(i);
		}
	}
	return ret;
}

