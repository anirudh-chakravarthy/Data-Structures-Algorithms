#ifndef _TREE
#define _TREE


struct node {
	char key[30];
	struct node** children;
	int count; // number of children for each node
};


// create an empty tree
struct node* createTree();

// read data from the file and choice to operate on the tree
struct node* readData(FILE* f, struct node* root);

// insert into tree
struct node* insert(struct node* root, char name[30], char ip[30]);

// search for ip address using name
void lookup(struct node* root, char* name);


#endif