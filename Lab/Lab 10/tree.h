#ifndef _TR
#define _TR


struct node {
	int value;
	struct node* left;
	struct node* right;
	int balanceFactor;
};


struct node* insert(struct node* root, int value);

int find(struct node* root, int value);

struct node* delete(struct node* root, int value);

struct node* nextNode(struct node* root);

void inOrderTraversal(struct node* root);

struct node* rotate(struct node* root, struct node* x, struct node* y, struct node* z);

#endif
