/*
Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, as any calculator would confirm that 2^11 = 2048 < 3^7 = 2187.

However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.

This program tries to take log of both side and compare the results. This method is successful using normal scientific calculator.

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;


int main(int argc, const char *argv[]) {
	int a[2];
	int i, j = 1;
	double val;
	double maxVal = 0;
	int max = 0;
	string value;
	ifstream data("base_exp.txt");
	if (!data.is_open()) {
		cout << "the base_exp.txt file cannot be opened." << endl;
		return 1;
	}

	string line;
	while (getline(data,line)){
		stringstream linestream(line);

		i = 0;
		while ( getline(linestream, value, ',')){
			istringstream buffer(value);
			buffer >> a[i];
			i++;
		}
		cout << a[0] << '\t' << a[1] << endl;
		val = a[1] * log( a[0]);
		if (val > maxVal) {
			maxVal = val;
			max = j;
		}
		j++;
	}
	cout << "Max is " << max << endl;
	return 0;
}
