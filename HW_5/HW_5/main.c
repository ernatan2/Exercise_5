#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#define  memory_allocation \
do{\
printf("Memory allocation problem\n"); \
exit(1); \
}while(0)



int main() {
	BST* tree;
	int N = 4;
	tree = NULL;
	tree = (BST*)malloc(sizeof(BST));
	if (!tree) {
		memory_allocation;
	}
	initBST(tree);
	printTreeInorder(tree);
	findIndexNFromLast(tree, 4);
	sameHeightLeaves(tree);


	// Implanting the tree
	insertBST(tree, 5);
	insertBST(tree, 2);
	insertBST(tree, 8);
	insertBST(tree, 9);
	insertBST(tree, 4);
	insertBST(tree, 1);
	printTreeInorder(tree);
	printf("the %d number is:%d\n",N , findIndexNFromLast(tree, N));
	if (!sameHeightLeaves(tree)) {
		printf("The leaves aren't at the same height\n");
	}
	else {
		printf("The leave are at the same height\n");
	}
	destroyBST(tree);
}