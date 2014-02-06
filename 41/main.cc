//Pandigital prime 

/*We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/

#include <iostream>
#include "pandigitalPrime.h"
#include "numberTheory.h"
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
	//listAllPandigitalPrime();
	int j = 0;
	int sum = 0;
	int max = 0;
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);

	//Pandigital Prime starts with 4 digits
	for (int i = 4; i < 10; i++) {
		mylist.push_back(i);
		do {
			j = 0;
			sum = 0;
			for (std::list<int>::iterator lt = mylist.begin(); lt != mylist.end(); lt++) {
				sum += pow(10, j) * *lt;
				j++;
			}
			if (isPrime(sum)) {
				if (max < sum) {
					max = sum;
				}
				cout << max << '\t';
			}
		} while (next_permutation(mylist.begin(), mylist.end()));
	}
	
	return 0;
}
