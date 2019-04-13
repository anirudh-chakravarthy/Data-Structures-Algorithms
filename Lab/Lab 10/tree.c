#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


int height(struct node* root) {
	if(root == NULL)
		return 0;

	int lDepth = height(root->left);
	int rDepth = height(root->right);

	if(lDepth > rDepth)
		return lDepth + 1;
	else
		return rDepth + 1;
}


struct node* insert(struct node* root, int value) {
	if(root == NULL) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->balanceFactor = 0;
		return newNode;
	}

	if(value < root->value) 
		root->left = insert(root->left, value);

	else if(value > root->value) 
		root->right = insert(root->right, value);

	int lheight = height(root->left);
	int rheight = height(root->right);
	root->balanceFactor = lheight - rheight;

	// left-left case: Right rotate
	if(root->balanceFactor > 1 && value < root->left->value) 
		return rotate(root->left->left, root->left, root);

	// right-right case: left rotate
	else if(root->balanceFactor < -1 && value > root->right->value) 
		return rotate(root, root->right, root->right->right);

	// left-right case: left and then right rotate
	else if(root->balanceFactor > 1 && value > root->left->value) {
		root->left = rotate(root->left, root->left->right, root->left->right->right);
		return rotate(root->left->left, root->left, root);
	}

	// right-left case: right and then left rotate
	else if(root->balanceFactor < -1 && value < root->right->value) {
		root->right = rotate(root->right->left->left, root->right->left, root->right);
		return rotate(root, root->right, root->right->right);
	}
	return root;
}


struct node* find(struct node* root, int value) {
	if(root == NULL || value == root->value)
		return root;

	if(value < root->value)
		return find(root->left, value);

	else
		return find(root->right, value);
}


struct node* delete(struct node* root, int value) {
	// if tree is empty
	if(root == NULL)
		return root;

	if(value < root->value) {
		root->left = delete(root->left, value);
		return root;
	}

	else if(value > root->value) {
		root->right = delete(root->right, value);
		return root;
	}

	else {

		// leaf node
		if(root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}

		// only left child
		else if(root->left != NULL && root->right == NULL) {
			struct node* tmp = root->left;
			free(root);
			return tmp;
		}

		// only right child
		else if(root->left == NULL && root->right != NULL) {
			struct node* tmp = root->right;
			free(root);
			return tmp;
		}

		// 2 children
		else {
			struct node* tmp = successor(root);
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


struct node* rotate(struct node* x, struct node* y, struct node* z) {
	struct node* a = x;
	struct node* b = y;
	struct node* c = z;

	struct node* t0 = x->left;
	struct node* t1 = x->right;
	struct node* t2 = y->right;
	struct node* t3 = z->right;

	b->left = a;
	b->right = c;

	a->left = t0;
	a->right = t1;

	c->left = t2;
	c->right = t3;

	b->balanceFactor = height(b->left) - height(b->right);
	c->balanceFactor = height(c->left) - height(c->right);
	return b;
}



void inOrderTraversal(struct node* root) {
	if(root != NULL) {
		inOrderTraversal(root->left);
		printf("%d\n", root->value);
		inOrderTraversal(root->right);
	}
}