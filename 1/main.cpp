/*
 * 2013-12-23
 * © Copyright 2013 Ce Ji. All Rights Reserved.
 *
 * This program find the sum of all the multiples
 * of 3 or 5 below 1000.
 *
 */
#include "iostream"

#define FIRST 3
#define SECOND 5
#define LIMIT 1000

using namespace std;

int sumOfMultiple(int a, int b, int limit);

int main(int argc, const char *argv[])
{
	cout << sumOfMultiple(FIRST, SECOND, LIMIT) << endl;
	return 0;
}

int sumOfMultiple(int a, int b, int limit){
	int sum = 0;
	for (int i = 0; i < limit; i++) {
		if (i % a == 0 || i % b == 0) {
			sum += i;
		}
	}
	return sum;
}
