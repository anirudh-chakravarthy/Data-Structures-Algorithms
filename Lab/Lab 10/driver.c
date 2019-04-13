#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


int main() {
	struct node* root = NULL;
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 8);

	printf("Height: %d\n", height(root->right->right->right));

	inOrderTraversal(root);

	// root = delete(root, 3);
	// inOrderTraversal(root);

}