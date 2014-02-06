/*
By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:

Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
 */
#include <iostream>
#include <cmath>

using namespace std;

long rectangle_number(int, int);

int main(int argc, const char *argv[])
{
	const long MAX = 2000000;	// MAX is the required number of rectangles 
	const int MARGIN = 555;		// Arbitrary margin to break l loop
	const int RECLIM = 3000;	// my artificial limit 
	int reclimit = RECLIM;		// the next i loop should be shorter
	long tmp, diff, min = MAX;	// tmp for storing # of rec in the loop
	cout << "3 \\times 2 gets " << rectangle_number(3,2) << endl;
	for (int i = 1; i < RECLIM; i++) {
		for (int l = i; l <= reclimit; l++) {
			tmp = rectangle_number(i, l);
			// break off when # of rec gets too large and set # of next loop
			if ( tmp > MAX + MARGIN){
				reclimit = l;
				break;
			}
			diff = abs(MAX - tmp);
			if ( diff < min) {
				min = diff;
				cout << i << '\t' << l << '\t' << tmp << '\t' << min <<'\t'<<  i*l << endl;
			}
		}
	}
	
	cout << "Minimum is " << min << endl;
	return 0;
}

long rectangle_number(int a, int b){
	long sum = 0;
	for (int i = 1; i <= a; i++) {
		for (int l = 1; l <= b; l++) {
			sum += i * l;
		}
	}
	return sum;
}
