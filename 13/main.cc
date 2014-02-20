/*
 * Work out the first ten digits of the sum of the following one-hundred
 * 50-digit numbers in sum.txt
 *
 * The data has to be changed to a vector of pointers to the actual data
 * array.
 */

#include <iostream>
#include <sstream>
#include <fstream> 
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	fstream input("sum.txt");
	if (!input.is_open()) {
		cout << "IO ERROR!!!";
		return 1;
	}

	// input the fist line
	string firstline;
	getline(input, firstline);
	vector<int> line;
	stringstream num;
	num << firstline;
	char var;
	while( num.get(var) ){
		stringstream tmp;
		tmp << var;
		int value;
		tmp >> value;
		line.push_back(value);
	}
	
	// determine the # of digits the numbers have
	int size = line.size();
	vector<int*> data;
	data.push_back(NULL);
	data[0] = new int[size];
	// copy the first line into the permanent data matrix
	for (int i = 0; i < size; ++i) {
		data[0][i] = line[i];
	}
	
	// read rest of the file and load data into data matrix
	int i = 1;
	while (getline(input, firstline)) {
		data.push_back(NULL);
		data[i] = new int[size];
		stringstream num_line;
		num_line << firstline;
		int j = 0;
		while (num_line.get(var)) {
			stringstream tmp;
			tmp << var;
			int value;
			tmp >> value;
			data[i][j] = value;
			j++;
		}
		i++;
	}
	int length = i;

	//Adding them up, digit to digit, backwards
	int *sum = new int[size];
	int *up = new int[size + 1];
	up[size] = 0;
	int inisum;
	for (int i = size - 1; i >= 0; --i) {
		inisum = 0;
		for (int j = 0; j < length; ++j) {
			inisum += data[j][i];
		}
		inisum += up[i + 1];
		sum[i] = inisum % 10;
		up[i] = (inisum - sum[i]) / 10;
	}

	// output the results.
	cout << up[0];
	for (int i = 0; i < size; ++i) {
		cout << sum[i];
	}
	cout << endl;

	return 0;
}
