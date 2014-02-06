/* n! means n × (n − 1) × ... × 3 × 2 × 1
For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
Find the sum of the digits in the number 100!

Algorithm failure!!!!!!

Revisit

*/

#include <iostream>
#include <cmath>

int iterationMethod(int);
int iteratorSum(int, int);
int digitSum(int n);

using namespace std;

int main(int argc, const char *argv[])
{
	unsigned int n = 11;
	cout << "11111" << '\t' << digitSum(11111) << endl;
	cout << "iteratorSum of 11 and 55" << '\t' << iteratorSum(11, 55) << endl;
	cout << "94720" << '\t' << digitSum(94720) << endl;
	cout << "iteratorSum of 40320 and 9" << '\t' << iteratorSum(40320, 9) << endl;
	cout << iterationMethod(n) << endl;
	cout << "iteratorSum of 9 and 10" << '\t' << iteratorSum(9, 10) << endl;
	return 0;
}

int iterationMethod(int n){
	int sum = 2;
	for (int i = 3; i <= n; i++) {
		sum = iteratorSum(sum, i);
		cout << i << '\t'<< tgamma(i+1) <<'\t' << sum << endl;
	}
	return sum;
}


int iteratorSum(int previous, int next){
	int tmp, sum = 0;
	int nextLength = ceil( log(next)/log(10) );
	//cout << "nextLength" << '\t' << nextLength << endl;
	for (int i = nextLength - 1; i >= 0; i--) {
		tmp = next / (pow(10, i));
		//cout << "tmp" << '\t' << tmp << endl;
		sum += digitSum(previous * tmp);
		//cout << "sum" << '\t' << sum << endl;
		next -= tmp * (pow(10, i));
	}
	return sum;
}

int digitSum(int n){
	int tmp, sum = 0;
	//cout << "n" << '\t' << n << endl;
	int length = ceil( log(n)/log(10) );
	//cout << "length" << '\t' << length << endl;
	for (int i = length - 1; i >= 0; i--) {
		tmp = n / (pow(10, i));
		n -= tmp * (pow(10, i));
		sum += tmp;
	}
	return sum;
}

