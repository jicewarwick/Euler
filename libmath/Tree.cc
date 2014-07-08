#include "Tree.h"

using namespace std;

Tree::Tree(){
	size_ = -1;
	data_ = NULL;
	minTree_ = NULL;
}

Tree::Tree(int** input, int n){
	size_ = n;
	data_ = input;
	genMinTree();
}

Tree::~Tree(){
	size_ = -1;
	for (int i = 0; i < size_; ++i) {
		delete[] data_[i];
		delete[] minTree_[i];
	}
	delete[] data_;
	delete[] minTree_;
	data_ = NULL;
	minTree_ = NULL;
}

void Tree::genMinTree(){
	// initialise minTree_ and tmp matrix
	minTree_ = new int*[size_];
	int** tmp = new int*[size_];
	for (int i = 0; i < size_; ++i) {
		minTree_[i] = new int[size_]();
		tmp[i] = new int[size_];
		// the first row is not needed as the algorithm start from the
		// first row
		for (int j = 1; j < size_; ++j) {
			tmp[i][j] = data_[i][j];
		}
	}
	
	// accepted vector stores the nodes that has been visited
	vector<int> accepted;
	accepted.push_back(0);
	int x, y, loop_x;
	for (int l = size_; l > 0; --l) {
		int min = INT_MAX;
		for (int i = 0; i < accepted.size(); ++i) {
			loop_x = accepted[i];
			for (int j = 1; j < size_; ++j) {
				if (tmp[loop_x][j] != 0 && min > tmp[loop_x][j]) {
					min = tmp[loop_x][j];
					x = loop_x;
					y = j;
				}
			}
		}
		accepted.push_back(y);
		minTree_[x][y] = tmp[x][y];
		for (int i = 0; i < size_; ++i) {
			tmp[i][y] = 0;
		}
	}

	// cleaning up the tmp matrix
	for (int i = 0; i < size_; ++i) {
		delete[] tmp[i];
	}
	delete[] tmp;

}

int Tree::minDistance(){
	if (data_ == NULL ) {
		return -1;
	}
	int ret = getTotalDistance(minTree_);
	return ret;
}

int Tree::initialDistance(){
	if (data_ == NULL ) {
		return -1;
	}
	int ret = getTotalDistance(data_);
	return ret;
}

int Tree::getTotalDistance(int** input){
	int sum = 0;
	for (int i = 0; i < size_; ++i) {
		for (int j = 0; j < size_; ++j) {
			sum += input[i][j];
		}
	}
	return sum;
}

void Tree::printTree(){
	printData(data_);
}

void Tree::printMinTree(){
	printData(minTree_);
}

void Tree::printData(int** input){
	for (int i = 0; i < size_; ++i) {
		for (int j = 0; j < size_; ++j) {
			cout << input[i][j] << '\t';
		}
		cout << endl;
	}
}
