#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


int main() {
	struct node* root = NULL;
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 4);
	
//	printf("%d\n", find(root, 2)); 
//	printf("%d\n", find(root, 5)); 

	root = delete(root, 2);
	inOrderTraversal(root);
}
