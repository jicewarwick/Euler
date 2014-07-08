/* Problem 136
 * The positive integers, x, y, and z, are consecutive terms of an arithmetic progression. Given that n is a positive integer, the equation, x^2 − y^2 − z^2 = n, has exactly one solution when n = 20:
 *
 * 13^2 − 10^2 − 7^2 = 20
 *
 * In fact there are twenty-five values of n below one hundred for which the equation has a unique solution.
 *
 * How many values of n less than fifty million have exactly one solution?
 */

#include <iostream>
#include <cmath>
#include <vector>
#include "numberTheory.h"

int main(int argc, char *argv[]) {
	long single_sol_counter = 0;
	int num_of_sol = 0;
	long x_tmp;
	long d_tmp;
	std::vector<long> x;
	std::vector<long> d;
	std::vector<long> singleton;

	const long kTEST = 100;
	const long kMAX = 50000000;
	
	for (long n = 1; n < kTEST; ++n) {
		num_of_sol = 0;
		for (long i = ceil(sqrt(n)); i < n; ++i) {
			if (n % i == 0) {
				d_tmp = (n/i + i);
				if (d_tmp % 4 == 0 && d_tmp/4 < i && d_tmp > 0) {
					x_tmp = i;
					++num_of_sol;
				}
			}
		}
		if (num_of_sol == 1) {
			++single_sol_counter;
			x.push_back(x_tmp);
			d.push_back(d_tmp/4);
			singleton.push_back(n);
		}
	}
	std::cout << single_sol_counter << std::endl;
	for (int i = 0; i < single_sol_counter; ++i) {
		std::cout << x[i] - d[i] << '\t' << x[i] << '\t' << x[i] + d[i] << '\t' << singleton[i] << std::endl;
	}
	return 0;
}
