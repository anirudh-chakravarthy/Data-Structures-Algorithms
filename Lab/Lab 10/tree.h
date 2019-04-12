#ifndef _TREE
#define _TREE


struct node {
	int value;
	struct node* left; // left child 
	struct node* right; // right child
	int balanceFactor; // height(left subtree) - height (right subtree)
};


// insert value into the tree
struct node* insert(struct node* root, int value);

// search for value in the tree
struct node* find(struct node* root, int value);

// delete value from the tree
struct node* delete(struct node* root, int value);

// find successor of value in the tree
struct node* successor(struct node* root);

// in order traversal of the tree
void inOrderTraversal(struct node* root);

// rotate AVL tree
struct node* rotate(struct node* x, struct node* y, struct node* z);


#endif