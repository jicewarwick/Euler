/*
In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.
	
131	673	234	103	18
201	96	342	965	150
630	803	746	422	111
537	699	497	121	956
805	732	524	37	331

Find the minimal path sum, in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.
*/

#include <iostream>
#include <fstream>
#include <sstream>

#define SIZE 80

using namespace std;
void output_matrix(const int[][SIZE], const int);

int main(int argc, const char *argv[])
{
	int matrix[SIZE][SIZE];
	string line;
	
	// import the matrix into matrix variable
	ifstream data("matrix.txt");

	if ( !data.is_open()) {
		cout << "Can't find matrix.txt, exit!" << endl;
		return 1;
	}
	int i = 0;
	while (getline(data,line)){
		stringstream linestream(line);
		string value;
		int j = 0;

		while ( getline(linestream, value, ',')){
			istringstream buffer(value);
			int num;
			buffer >> num;
			matrix[i][j] = num;
			j++;
		}
		i++;
	}

	output_matrix(matrix, SIZE);
	
	// initialise the distance matrix
	long distance[SIZE][SIZE];
	long sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += matrix[0][i];
		distance[0][i] = sum;
	}
	sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += matrix[i][0];
		distance[i][0] = sum;
	}

	//fill the distance matrix row by row
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			distance[i][j] = min(distance[i-1][j], distance[i][j-1]) + matrix[i][j];
		}
	}
	//output_matrix(distance, SIZE);
	
	cout << distance[SIZE-1][SIZE-1] << endl;

	return 0;
}

void output_matrix(const int input[][SIZE], const int n){
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			cout << input[i][l] << '\t';
		}
		cout << endl;
	}

}
