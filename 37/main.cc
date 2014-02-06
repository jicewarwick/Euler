/*
 * The number 3797 has an interesting property. Being prime itself, it is
 * possible to continuously remove digits from left to right, and remain prime
 * at each stage: 3797, 797, 97, and 7. Similarly we can work from right to
 * left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left to
 * right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 *
 * My note:
 * A better idea to test from right is to find the remainder of the number
 * divided by 10^x. This way, no manipulation for the input number is needed.
 *
 * Testing from the left is easy as it is simply the inverse from right.
 *
 * Instead of using vectors in C++, it is a lot easier to use C utility to
 * manipulate integer as strings
 */


#include <iostream>
#include "numberTheory.h"
#include <vector>

using namespace std;

vector<int> get_chuncated(int);
bool isChuncatableprime(int);

int main(int argc, const char *argv[])
{
	int num = 23;
	int i = 0;
	int sum = 0;

	do {
	   if (isChuncatableprime(num)) {
	   	cout << num << endl;
		sum += num;
	   	i++;
	   }
	   num++;
	 } while (i < 11);
	 cout << sum << endl;
	return 0;
}

vector<int> get_chuncated(int n){
	vector<int> ret;
	int length = ceil(log(n) / log(10));
	for (int i = 0; i < length; i++) {
		int magnitude = pow(10, length - 1 - i);
		int digit = n / magnitude;
		ret.push_back(digit);
		n -= digit * magnitude;
	}
	return ret;
}


bool isChuncatableprime(int n){
	bool ret = false;
	if (isPrime(n)) {
		int l = 0;
		vector<int> tmp = get_chuncated(n);
		int tmpSize = tmp.size();

		//check from left
		int test = 0;
		for (l = 0; l < tmpSize - 1; l++) {
			test += tmp[tmpSize - 1 -l] * pow(10, l);
			if (!isPrime(test)) {
				return ret;
			}
		}

		// check from right
		test = n;
		for (l = 0; l < tmpSize - 1; l++) {
			test -= (test % 10);
			test /= 10;
			if (!isPrime(test)) {
				return ret;
			}
		}
		ret = true;
	}
		
	return ret;
}
