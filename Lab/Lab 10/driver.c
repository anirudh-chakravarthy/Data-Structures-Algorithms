#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


int main() {
	struct node* root = NULL;

	root = insert(root, 10);
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 15);
	root = insert(root, 7);
	root = insert(root, 11);
	root = insert(root, 12);
	root = insert(root, 14);

	inOrderTraversal(root);	

	// struct node* tmp = find(root, 2);
	// printf("Found: %d\n", tmp->value);
	// tmp = find(root, 5);
	// printf("%d\n", tmp->value);

	// root = delete(root, 2);
	// inOrderTraversal(root);

	// printf("Second Min is: %d\n", findMin(root, 2));
	rangeSearch(root, 7, 12);
	for(int i = 0; i < num_elements; i++)
		printf("%d ", arr[i]);
	printf("\n");
}