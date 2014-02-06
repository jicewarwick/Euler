/*
Champernowne's constant

An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

using namespace std;

long long chunk_length(int i);
int return_digit(long long n);

int main(int argc, const char *argv[])
{
	int ans = 1;
	for (int i = 0; i < 7; i++) {
		ans *= return_digit(pow(10, i));
	}
	cout << ans << endl;
	return 0;
}
long long chunk_length(int i){
	return ( i * 9 * pow(10, i-1) );
}

int return_digit(long long n){
	int i = 1;
	while (n > chunk_length(i) ){
		n -= chunk_length(i);
		i++;
	}
	//cout << "The length: " << i << endl;
	
	string str;
	int ans;
	int pre = n / i + pow(10, i - 1) - 1;
	int over = n % i;
	int place = 0;
	stringstream convert_to_int;
	if (over == 0) {
		place = i;
		convert_to_int << pre;
	} else {
		place = over;
		convert_to_int << (pre + 1);
	}
	convert_to_int >> str;
	stringstream convert_to_int1;
	convert_to_int1 << str[place - 1];
	convert_to_int1 >> ans;

	return ans;
}
