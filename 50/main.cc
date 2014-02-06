/* 
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/ 

#include <iostream>
#include <vector>
#include "numberTheory.h"

using namespace std;

void list_vector(const vector<int> &);

int main(int argc, const char *argv[])
{
	const int MAX = 1000000;

	vector<int> prime;

	// find all the primes and store it in a vector
	for (int i = 2; i < MAX; i++) {
		if (isPrime(i)) {
			prime.push_back(i);
		}
	}

	// find the largest by looping over n sums
	
	int max = 0;
	long sum = 0;
	// i for the position and n for the number of primes
	
	int size = prime.size();
	for (int n = 2; n < size / 2; n++) {
		for (int i = 0; i < size - n; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += prime[i + j];
			}
			if (sum > MAX) {
				break;
			}
			if ( isPrime(sum) ) {
				max = n;
				cout << sum << endl;
				break;
			}
		}
	}
	return 0;
}
