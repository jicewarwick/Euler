/* 
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
This program find the largest prime that is the sum of consecutive primes (at least two).
*/ 

#include <iostream>
#include <vector>
#include "numberTheory.h"

using namespace std;

void list_vector(const vector<int> &);

int main(int argc, const char *argv[])
{
	const int MAX = 1000;

	vector<int> prime;

	// find all the primes and store it in a vector
	for (int i = 2; i < MAX; i++) {
		if (isPrime(i)) {
			prime.push_back(i);
		}
	}

	list_vector(prime);
	// find the largest by looping over n sums
	
	int max = 0;
	int sum = 0;
	// i for the position and n for the number of primes
	cout << "Prime Vector size " << prime.size() << endl;
	for (int n = 2; n < prime.size(); n++) {
		for (int i = 0; prime[i] <= MAX / n; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += prime[i + j];
			}
			if (sum > MAX) {
				break;
			}
			if ( sum > max && isPrime(sum)) {
				max = sum;
				cout << "Currently, we have n = " << n << ", i = " << i << " and sum = " << sum << endl;
			}
		}
		//cout << "n: " << n << endl;
	}
	cout << "Max is " << max << endl;
	return 0;
}


void list_vector(const vector<int> &vec){
	for (int i = 0; i < vec.size(); i++) {
			cout << i << '\t' << vec[i] << endl;
	}
}
