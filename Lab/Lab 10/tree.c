#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


struct node* insert(struct node* root, int value) {	

	// if tree is empty
	if(root == NULL) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->balanceFactor = 0;
		return newNode;
	}

	// lesser so insert in left subtree
	if(value < root->value) {
		root->balanceFactor++;
		root->left = insert(root->left, value);
		
		// if root is now imbalanced
		if(root->balanceFactor > 1) {
			struct node* grandChild;
			if(value < root->left->value)
				grandChild = root->left->left;
			else
				grandChild = root->left->right;

			root = rotate(grandChild, root->left, root);
			root->balanceFactor++;
		}
		return root;
	}

	// greater so insert in right subtree
	else {
		root->balanceFactor--;
		root->right = insert(root->right, value);

		// if root is now imbalanced
		if(root->balanceFactor < -1) {
			struct node* grandChild;
			if(value < root->right->value) 
				grandChild = root->right->left;
			else
				grandChild = root->right->right;

			root = rotate(grandChild, root->right, root);
		}
		return root;
	}
}


struct node* find(struct node* root, int value) {
	if(root == NULL || root->value == value)
		return root;

	// search in left subtree
	else if(value < root->value)
		return find(root->left, value);

	// search in right subtree
	else
		return find(root->right, value);
}


struct node* delete(struct node* root, int value) {

	// element not found in the tree
	if(root == NULL) {
		printf("Element: %d not in tree\n", value);
		return root;
	}

	// delete from left subtree
	if(value < root->value) {
		root->left = delete(root->left, value);
		return root;
	}

	// delete from right subtree
	else if(value > root->value) {
		root->right = delete(root->right, value);
		return root;
	}

	// node found
	else {
		// leaf node
		if(root->left == NULL && root->right == NULL) {
			printf("Deleted: %d\n", root->value);
			free(root);
			return NULL;
		}

		// only left child
		else if(root->right == NULL) {
			printf("Deleted: %d\n", root->value);
			struct node* lChild = root->left;
			free(root);
			return lChild;
		}

		// only right child
		else if(root->left == NULL) {
			printf("Deleted: %d\n", root->value);
			struct node* rChild = root->right;
			free(root);
			return rChild;
		}

		// two children 
		else {
			printf("Deleted: %d\n", root->value);
			struct node* tmp = successor(root);
			printf("Successor: %d\n", tmp->value);
			root->value = tmp->value;
			root->right = delete(root->right, tmp->value);
			return root;
		}
	}
}


struct node* successor(struct node* root) {
	struct node* tmp = root->right;
	while(tmp->left != NULL) 
		tmp = tmp->left;
	return tmp;
}


void inOrderTraversal(struct node* root) {
	if(root != NULL) {
		inOrderTraversal(root->left);
		printf("%d\n", root->value);
		inOrderTraversal(root->right);
	}
}


struct node* rotate(struct node* x, struct node* y, struct node* z) {
	struct node* a = x;
	struct node* b = y;
	struct node* c = z;

	struct node* t0;
	struct node* t1;
	struct node* t2;
	struct node* t3;
	
	// left-left case
	if(y == z->left && x == y->left) {
		t0 = x->left;
		t1 = x->right;
		t2 = y->right;
		t3 = z->right;
	}

	// right-right case
	else if(y == z->right && x == y->right) {
		t0 = z->left;
		t1 = y->left;
		t2 = x->left;
		t3 = x->right;
	}

	// left-right case
	if(y == z->left && x == y->right) {
		t0 = y->left;
		t1 = x->left;
		t2 = x->right;
		t3 = z->right;
	}

	// right-left case
	if(y == z->right && x == y->left) {
		t0 = z->left;
		t1 = x->left;
		t2 = x->right;
		t3 = y->right;
	}

	// swap z and b
	struct node* tmp = b;
	b = z;
	z = tmp;

	// adjust children of b
	b->left = a;
	b->right = c;

	// adjust children of a
	a->left = t0;
	a->right = t1;

	// adjust children of c
	c->left = t2;
	c->right = t3;
	return b;
}
