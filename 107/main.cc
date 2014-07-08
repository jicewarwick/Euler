/*
 *Using network.txt (right click and 'Save Link/Target As...'), a 6K text file
 containing a network with forty vertices, and given in matrix form, find the
 maximum saving which can be achieved by removing redundant edges whilst
 ensuring that the network remains connected.)
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Tree.h"

#define INPUT "net"

using namespace std;

int main(int argc, char const *argv[])
{
	int dist;
	vector<int> first_line;
	string line;
	string var;
	stringstream dash;
	dash << "-";
	
	// read in the file as a matrix
	ifstream input(INPUT);
	//ifstream input("network.txt");
	if (!input.is_open()) {
		cout << "IO ERROR!!!" << endl;
		return 1;
	}
	getline(input, line);
	stringstream linestream(line);
	while (getline(linestream, var, ',')){
		stringstream tmp(var);
		if (tmp == dash) {
			first_line.push_back(0);
		} else{
			tmp >> dist;
			first_line.push_back(dist);
		}
	}
	int size = first_line.size();
	cout << "size is " << size << endl;

	int** data = new int*[size];
	data[0] = new int[size];
	for (int i = 0; i < size; ++i) {
		data[0][i] = first_line[i];
	}
	for (int i = 1; i < size; ++i) {
		data[i] = new int[size];
		int j = 0;
		getline(input, line);
		stringstream linestream2(line);
		while (getline(linestream2, var, ',')){
			stringstream tmp(var);
			if (tmp == dash) {
				data[i][j] = 0;
			} else{
				tmp >> dist;
				data[i][j] = dist;
			}
			j++;
		}
	}
	Tree map(data, size);
	int total_distance = map.initialDistance();
	int min_distance = map.minDistance();
	cout << "The total distance of the map: " << total_distance << endl;
	//map.printTree();
	cout << "The minimum tree is of size: " << min_distance << endl;
	map.printMinTree();
	cout << "Total saving: " << total_distance - min_distance << endl;
	map.~Tree();
	
	return 0;
}

