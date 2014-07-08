/*
 * Digit factorials
 *
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the
 * factorial of their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 *
 * */

#include<iostream>
#include<vector>

using namespace std;

bool testDigitFactorial(const unsigned long, const int, const unsigned long*);

int main(){
	const int MAX_SIZE = 8;
	unsigned int digit[10];
	unsigned long fac[10];
	unsigned long sum = 0;

	// initialise the array that store digits and their factorials
	digit[0] = 0;
	fac[0] = 1;
	unsigned long tmp = 1;
	for (int i = 1; i < 10; ++i) {
		digit[i] = i;
		tmp *= i;
		fac[i] = tmp;
	}

	for (int length = 2; length < MAX_SIZE; ++length) {
		// fac_can is used to store the candidate for each testing
		unsigned long *fac_can = new unsigned long[length];
		for (int i = 0; i < length; ++i) {
			fac_can[i] = i;
		}

		do {
			unsigned long fac_sum = 0;
			for (int j = 0; j < length; j++){
				fac_sum += fac[fac_can[j]];
			}
			if (testDigitFactorial(fac_sum, length, fac)) {
				cout << fac_sum << endl;
				sum += fac_sum;
			}
			for (int j = 0; j < length; j++){
				if (fac_can[j] != 9){
					fac_can[j]++;
					break;
				} else {
					fac_can[j] = 0;
				}
			}
		} while( fac_can[length -1] != 9 || fac_can[0] != 9 );
		
	}
	cout << "The sum of all digit factorials is " << sum << endl;
}

bool testDigitFactorial(const unsigned long input, const int length, const unsigned long* factorial){
	bool ret = false;
	unsigned long fac_sum_copy = input;

	// split the fac_sum_copy into individual digits
	vector<int> digits;
	do {
		int digit = fac_sum_copy % 10;
		digits.push_back(digit);
		fac_sum_copy = (fac_sum_copy - digit) / 10;
	} while (fac_sum_copy > 0);

	int digits_size = digits.size(); 
	if ( digits_size == length ){
		unsigned long digits_sum = 0;
		for (int j = 0; j < digits_size; j++){
			digits_sum += factorial[digits[j]];
		}
		if (digits_sum == input){
			ret = true;
		}
	}
	return ret;
}
