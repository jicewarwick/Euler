#ifndef MINTREE_H_PBEHVL53
#define MINTREE_H_PBEHVL53

#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>

class Tree {
	public:
		Tree();
		Tree(int**, int);
		~Tree();
		int minDistance();
		int initialDistance();
		void printTree();
		void printMinTree();

	private:
		int size_;
		int** data_;
		int** minTree_;
		void genMinTree();
		int getTotalDistance(int**);
		void printData(int**);
};

#endif /* end of include guard: MINTREE_H_PBEHVL53 */
