/*
 * There are exactly ten ways of selecting three from five, 12345:
 *
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 *
 * In combinatorics, we use the notation, ^5C_3 = 10.
 *
 * In general,
 * ^nCr = \frac{n!}{ r!(n−r)!}
 * 	,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
 *
 * 	It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
 *
 * 	How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are
 * 	greater than one-million?
 *
 * 	Since 100! is such a huge number, it is not possible to store it in the
 * 	memory it turns out that in order to prevent memory leak, the system would
 * 	initialise it to 0.
 *
 * 	Luckily, we only need to evaluate anything up to 1 million. I iterate in r
 * 	rather than n since for each r, increasing n would surely increase the
 * 	outcome. 
 *
 * 	Since large factorial is involved, the choose function has to be maintained
 * 	at minimum value. The CChoose function solves this problem by cancelling the
 * 	largest common factor first. 
 */

#include <iostream>
#include <numberTheory.h>

using namespace std;

long long int CChoose(int, int);

int main(int argc, const char *argv[]) {
	// the limit for n
	const int MAX = 100;
	// the limit for the number of choices
	const int LIMIT = 1000000;
	int sum = 0;

	// for each r, find the first n such that ^nC_r is bigger than LIMIT, then,
	// we can conclude that for this r, there are MAX - n + 1 of "n"s satisfying
	// this criteria.
	for (int r = 2; r < MAX; r++) {
		for (int n = r + 1; n <= MAX; n++) {
			if (CChoose(n, r) > LIMIT) {
				sum += MAX - n + 1;
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}

// as we know, ^nC_r is n!/(r!\times (n-r)!), it is more efficient to cancel n!
// with the largest of r! or (n-r)!
long long int CChoose(int n, int r){
	long long int ret = 1;
	
	int small = min(n - r, r);
	int big = max(n - r, r);
	
	for (int i = big + 1; i <= n; i++) {
		ret *= i;
	}
	for (int i = 2; i <= small; i++) {
		ret /= i;
	}
	return ret;
}
