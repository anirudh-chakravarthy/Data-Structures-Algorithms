#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"


int main() {
	FILE* f = fopen("input.txt", "r");
	struct node* root = createTree();
	
	root = readData(f, root);
	printf("\n");

	root = readData(f, root);
	root = readData(f, root);
	root = readData(f, root);
	root = readData(f, root);

	// Check if program terminated by file input
	printf("Program completed\n");
}