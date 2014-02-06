/* Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
#include <cmath>

using namespace std;

void findAmicableNumbers(int);
int sumProperDivisors(int);

int main(int argc, const char *argv[])
{
	findAmicableNumbers(10000);
	return 0;
}

void findAmicableNumbers(int n){
	long sum = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = sumProperDivisors(i);
		if (sumProperDivisors(tmp) == i && tmp != i) {
			sum += tmp;
			sum += i;
		}
	}
	cout << "sum" << '\t' << sum/2 << endl;
}


int sumProperDivisors(int n){
	int sum = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			sum += i;
			sum += (n / i);
		}
	}
	return (sum-n);
}
