#ifndef _TREE
#define _TREE


struct node {
	int value;
	struct node* left;
	struct node* right;
	int balanceFactor;
};


struct node* createTree();

int height(struct node* root);

struct node* insert(struct node* root, int value);

struct node* find(struct node* root, int value);

struct node* delete(struct node* root, int value);

struct node* successor(struct node* root);

struct node* rotate(struct node* x, struct node* y, struct node* z);

void inOrderTraversal(struct node* root);


#endif