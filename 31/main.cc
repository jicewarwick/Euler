/*
 * In England the currency is made up of pound, £, and pence, p, and there are
 * eight coins in general circulation:
 *
 *     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 *
 * It is possible to make £2 in the following way:
 *
 *         1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 *
 * How many different ways can £2 be made using any number of coins?
 *
 * Using recursive method. For every combination that evaluates less or equals
 * to  than 200p would be a new combination for the problem.
 *
 */

#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	int sum = 0;
	int to_one_pound, to_fifty_p, to_twenty_p, to_ten_p;
	int to_five_p, to_two_p;
	for (int onepound = 0; onepound < 3; onepound++) {
		to_one_pound = onepound * 100;
		for (int fiftyp = 0; fiftyp < 5; fiftyp++) {
			to_fifty_p = to_one_pound + 50 * fiftyp;
			for (int twentyp = 0; twentyp < 11; twentyp++) {
				to_twenty_p = to_fifty_p + 20 * twentyp;
				for (int tenp = 0; tenp < 21; tenp++) {
					to_ten_p = to_twenty_p + 10 * tenp;
					for (int fivep = 0; fivep < 41; fivep++) {
						to_five_p = to_ten_p + 5 * fivep;
						for (int twop = 0; twop < 101; twop++) {
							to_two_p = to_five_p + 2 * twop;
							if (to_two_p <= 200) {
								sum ++;
							}
						}
					}
				}
			}
		}
	}
	cout << sum + 1 << endl;	// +1 for the only a two pound coin method.
	return 0;
}
