/*
 * In the 5 by 5 matrix below, the minimal path sum from the top left to the
 * bottom right, by moving left, right, up, and down, is indicated in bold red
 * and is equal to 2297.
 *
 * 	131	673	234	103	18
 * 	201	96	342	965	150
 * 	630	803	746	422	111
 * 	537	699	497	121	956
 * 	805	732	524	37	331
 *
 * 	Find the minimal path sum, in matrix.txt (right click and 'Save
 * 	Link/Target As...'), a 31K text file containing a 80 by 80 matrix, from
 *	the top left to the bottom right by moving left, right, up, and down.'')
 *
 *	The algorithm reused the Problem 81 to base an initial path. Then, the
 *	algorithm iterates on each entry of the distance by comparing the current
 *	shortest path with the minimum of the path distance coming from four
 *	directions until no entry is changed.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#define SIZE 80

using namespace std;
void output_matrix(const long[][SIZE], const int);
long getMinToHere(const long[][SIZE], int, int);

int main(int argc, const char *argv[])
{
	int i = 0, j = 0;
	int num;
	long matrix[SIZE][SIZE];
	string line;
	
	// import the matrix into matrix variable
	ifstream data("matrix.txt");

	if ( !data.is_open()) {
		cout << "Can't find matrix.txt, exit!" << endl;
		return 1;
	}
	while (getline(data,line)){
		stringstream linestream(line);
		string value;
		j = 0;

		while ( getline(linestream, value, ',')){
			istringstream buffer(value);
			buffer >> num;
			matrix[i][j] = num;
			j++;
		}
		i++;
	}

	
	// initialise the distance matrix
	long distance[SIZE][SIZE];
	long toHere[SIZE][SIZE];	// store the shortest distance before arriving here.
	long sum = 0;
	for ( i = 0; i < SIZE; i++) {
		toHere[0][i] = sum;
		sum += matrix[0][i];
		distance[0][i] = sum;
	}
	sum = 0;
	for (i = 0; i < SIZE; i++) {
		toHere[i][0] = sum;
		sum += matrix[i][0];
		distance[i][0] = sum;
	}

	//fill the distance matrix row by row
	for (i = 1; i < SIZE; i++) {
		for (j = 1; j < SIZE; j++) {
			toHere[i][j] = min(distance[i-1][j], distance[i][j-1]);
			distance[i][j] = toHere[i][j] + matrix[i][j];
		}
	}
	
	bool changed = false;
	long minToHere;
	do {
		changed = false;
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				minToHere = getMinToHere(distance, i, j);
				if (minToHere < toHere[i][j]) {
					changed = true;
					toHere[i][j] = minToHere;
					distance[i][j] = minToHere + matrix[i][j];
				}
				
			}
		}
	} while (changed);

	cout << "Path sum is " << distance[SIZE-1][SIZE-1] << endl;

	return 0;
}

void output_matrix(const long input[][SIZE], const int n){
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			cout << input[i][l] << '\t';
		}
		cout << endl;
	}

}
long getMinToHere(const long input[][SIZE], const int i, const int j){
	const long MAX = 1000000;
	long minimal = MAX;
	long up, down, left, right;
	up = down = left = right = MAX;
	if (i > 0) {
		up = input[i - 1][j];
	} 

	if (j > 0) {
		left = input[i][j - 1];
	}

	if (i < SIZE - 1) {
		right = input[i + 1][j];
	}

	if (j < SIZE - 1) {
		down = input[i][j + 1];
	}
	long tmp1 = min(up, down);
	long tmp2 = min(left, right);
	minimal = min(tmp1, tmp2);
	return minimal;
}
