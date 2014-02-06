#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	const int n = 5;
	ifstream check_length ("data.dat");
	if (! check_length.is_open()) {
		cerr << "Fail to open file!";
		exit(1);
	}
	string line;
	int length = 0;
	while(!check_length.eof()){
		getline(check_length, line);
		length += line.length();
	}

	ifstream input ("data.dat");
	if (! input.is_open()) {
		cerr << "Fail to open file!";
		exit(1);
	}
	// determine the length of the data
	//cout << "Length of input is " << length << endl;
	vector<int> tmp;
	int max = 0;
	int pro = 1;
	int num = 0;
	for (int i = 0; i < n; i++) {
		num =  input.get()- 48;
		//cout << "num is " << num << endl;
		tmp.push_back( num );
		pro *= num;
	}
	max = pro;
	int index = 0;
	//cout << "Currently, max is " << max << endl;
	for (int i = 0; i < length - n; i++) {
		tmp.erase(tmp.begin());
		tmp.push_back( input.get() -48);
		
		int pro = 1;
		for (int l = 0; l < n; l++) {
			pro *= tmp[l];
		}
		if (pro > max) {
			max = pro;
			index = n + i;
		}
		//cout << "Currently, max is " << max << endl;
	}

	cout << "Max is " << max << endl;
	cout << "At position: " << index << endl;

	return 0;
}
