#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main() {
	struct node* root = NULL;

	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 2);
	inOrderTraversal(root);

	struct node* tmp = find(root, 3);
	printf("Found: %d\n", tmp->value);
	// tmp = find(root, 5);
	// printf("%d\n", tmp->value);

	root = delete(root, 3);
	inOrderTraversal(root);
}