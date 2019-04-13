#ifndef _TREE
#define _TREE


struct node {
	char key[30];
	struct node** children;
	int num_children;
};


struct node* createTree();

struct node* readData(FILE* f, struct node* root);

struct node* insert(struct node* root, char name[30], char ip[30]);

void lookup(struct node* root, char* name);

#endif