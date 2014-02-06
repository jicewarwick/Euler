#include "pandigitalPrime.h"

using namespace std;

void listAllPandigitalPrime(void){
	//Pandigital Prime starts with 4 digits
	int j = 0;
	int sum = 0;
	list<int> mylist = new list<int>(i);
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	for (int i = 4; i < 10; i++) {
		mylist.push_back(i);
		do {
			j = 0;
			sum = 0;
			for (int lt = mylist.begin(); lt < mylist.end(); lt++) {
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

}

