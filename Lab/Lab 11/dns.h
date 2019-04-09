#ifndef _DNS
#define _DNS


struct node {
	char key[30];
	struct node** children;
	int count; // number of children
};


typedef struct {
	struct node* root;
} tree;


tree* createTree();

tree* insert(tree* t, char* name, char* ip);

tree* delete(tree* t, char* name);

tree* readData(FILE* f, int n);

char* lookup(char* name);


#endif