#ifndef _TREE
#define _TREE


//  to find elements in range
int arr[15];
int num_elements;


struct node {
	int value;
	struct node* left; // left child 
	struct node* right; // right child
	int balanceFactor; // height(left subtree) - height (right subtree)
};


// find parent of x in the tree
struct node* parent(struct node* root, struct node* x);

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

// find kth smallest element in tree
int findMin(struct node* root, int k);

// find next node for a given node x
struct node* nextNode(struct node* root, struct node* x);

// find keys in range k1 to k2 in the tree
void rangeSearch(struct node* root, int k1, int k2);


#endif