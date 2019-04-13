#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"


int main() {
	FILE* f = fopen("input.txt", "r");
	int choice;
	struct node* root = createTree();;

	while(fscanf(f, "%d ", &choice) != EOF) {
		if(choice == -1)
			exit(1);

		else if(choice == 1) 
			root = readData(f, root);

		else if(choice == 2) {
			char name[30];
			fscanf(f, "%s\n", name);
			lookup(root, name);
		}
	} 
}