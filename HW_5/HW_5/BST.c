#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#define  memory_allocation \
do{\
printf("Memory allocation problem\n"); \
exit(1); \
}while(0)
#define nullPointerCheck(ptr) if(!ptr)  printf("The tree Isn't implaned\n"); return



BST* create(BST * bst) { //creating new leaf
	bst->root = (TreeNode*)malloc(sizeof(TreeNode)); 
	if (!bst->root) {
		memory_allocation;
	}
	bst->root->left = NULL;
	bst->root->right = NULL;
	return bst;
}

void initBST(BST* bst) {
	create(bst); //creating a leaf
	bst->root = NULL; //sets the pointer to point to NULL
}


void insertBST(BST* bst, int value) {
	if (!bst->root) { // checking if the pointer points to NULL
		create(bst); //creating new leaf
		bst->root->element = value; //equlizing the element in the leaf to NULL
		return;
	}
	else if (bst->root->element >= value) { //checking where to navigate the value
		insertBST(&bst->root->left, value);
	}
	else {
		insertBST(&bst->root->right, value);
	}
}

void printTreeInorder(BST* bst) {
	nullPointerCheck(bst->root); //check if the leaf is NULL poinhter
	printTreeInorder(&bst->root->left); //goes to the left leaf
	printf("%d ", bst->root->element); //prints the leaf
	printTreeInorder(&bst->root->right); // goes to the right leaf
}

void treeDestroy(BST* bst) {
	if (bst->root->left) { //entreing the function by recursion
		treeDestroy(&bst->root->left);
	}
	if (bst->root->right) {
		treeDestroy(&bst->root->right);
	}
	free(bst->root); //free the memory
}

void destroyBST(BST* bst) {
	nullPointerCheck(bst); 
	treeDestroy(bst); //calling the recurseve function 
	free(bst); // free the tree
}

int findIndexNFromLast(BST* bst, int N) {
	nullPointerCheck(bst->root);
	if (bst->root->right) { // going recursivly to the rightmost side to start counting from the largest number
		N--;	
		N = findIndexNFromLast(&bst->root->right, N); 
	}
	if (N == 1) { // if the N intiger equals to 1 it means that we found the number
		N = bst->root->element; // when the N intiger equals to 1 the func equalizing the N intiger to the element 
		return N;//and return the intiger
	}
	if (bst->root->left ) {
		N = findIndexNFromLast(&bst->root->left, N);

	}
	return N;
}


int compareLeaves(BST* bst, int level, int *leaf_level) {
	if (!bst->root) { //if the tree have only one leaf at the begining means that the leafs at the same level so it returns 1
		return 1;
	}
	if (!bst->root->left && !bst->root->right) { //if the left leaf and the right leaf are null ptr it means that we reach to a leaf
		if (!*leaf_level) { // to enter for the first time and equalize the leaf_level with the leftmost leaf level
			*leaf_level = level;
			return 1;
		}
		if (*leaf_level == level) { // checking if the leaf level equals to level and if so it means the leaf at same level
			return 1; 
		}
		return 0;
	}
	return compareLeaves(&bst->root->left, level+1, leaf_level) && compareLeaves(&bst->root->right, level+1, leaf_level); // doinfg a bloin expration to check if return 1 or 0
	}


int sameHeightLeaves(BST* bst) { 
	int level = 0, leaf_level = 0; // creating an intigers for the recursive function
	if (!compareLeaves(bst, level, &leaf_level)) { //checking the value that the recursive function returns
		return 0; // if it returns 0 it means the leaf aren't equals
	}
	return 1;
	
}