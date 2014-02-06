#include "pandigitalPrime.h"

using namespace std;

void listAllPandigitalPrime(void){
	int j = 0;
	int sum = 0;
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
				cout << sum << '\t';
			}
		} while (next_permutation(mylist.begin(), mylist.end()));
	}
}

int largestPandigitalPrime(){

	return 0;

}

