#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


struct node* insert(struct node* root, int value) {
	if(root == NULL) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode->value = value;
		newNode->balanceFactor = 0;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
		printf("Inserted: %d\n", value);
		return root;
	}
	
	struct node* tmp = root;
	while(1) {
		if(value < tmp->value) {
			if(tmp->left == NULL) {
				struct node* newNode = (struct node*) malloc(sizeof(struct node));
				newNode->value = value;
				newNode->balanceFactor = 0;
				newNode->left = NULL;
				newNode->right = NULL; 
				tmp->left = newNode;
				printf("Inserted: %d\n", value);
				return root;
			}
			tmp->left = insert(tmp->left, value);
			return root;
		}
		
		else {
			if(tmp->right == NULL) {
				struct node* newNode = (struct node*) malloc(sizeof(struct node));
				newNode->value = value;
				newNode->balanceFactor = 0;
				newNode->left = NULL;
				newNode->right = NULL;
				tmp->right = newNode;
				printf("Inserted: %d\n", value);
				return root;
			}
			tmp->right = insert(tmp->right, value);
			return root;
		}
	}
}
	
	
int find(struct node* root, int value) {
	struct node* tmp = root;
	
	while(tmp != NULL) {
		if(value < tmp->value) 
			tmp = tmp->left;
		else if(value > tmp->value) 
			tmp = tmp->right;
		else
			return 1; // found
	}
	return 0; //not found
}


struct node* delete(struct node* root, int value) {
	if(root == NULL){
		printf("Tree is empty!\n");
		return root;
	}

	struct node* tmp = root;
	if(value < tmp->value) {
		tmp->left = delete(tmp->left, value);
		return tmp;
	}
	
	else if(value > tmp->value) {
		tmp->right = delete(tmp->right, value);
		return tmp;
	}
	
	else {
		// leaf node
		if(tmp->left == NULL && tmp->right == NULL) {
			free(tmp);
			return NULL;
		}
		
		// only right child
		if(tmp->left == NULL) {
			struct node* lChild = tmp->left;
			free(tmp);
			return lChild;
		}
		
		// only left child
		if(tmp->right == NULL) {
			struct node* rChild = tmp->right;
			free(tmp);
			return rChild;
		}
		
		// if 2 children, recursively delete the successor
		struct node* successor = nextNode(tmp);
		printf("Successor: %d\n", successor->value);
		tmp->value = successor->value;
		tmp->right = delete(tmp->right, successor->value);
		return tmp;
	}
	
}


struct node* nextNode(struct node* root) {
	root = root->right;
	while(root->left != NULL) 
		root = root->left;
	return root;
}


void inOrderTraversal(struct node* root) {
	if(root == NULL) 
		return;
	
	inOrderTraversal(root->left);
	printf("%d\n", root->value);
	inOrderTraversal(root->right);
}	


struct node* rotate(struct node* x, struct node* y, struct node* z, int caseNo) {

	struct node* a = x;
	struct node* b = y;
	struct node* c = z;
	
	// left rotate
	if(caseNo == 0) {
		struct node* t0 = z->left;
		struct node* t1 = y->left;
		struct node* t2 = x->left;
		struct node* t3 = x->right;
		
		// swap values and pointers
		struct node tmp = *b;
		*b = *z;
		*z = tmp;
		struct node* temp = b;
		b = z;
		z = temp;
		
		b->left = c;
		b->right = a;
		c->left = t0;
		c->right = t1;
		a->left = t2;
		a->right = t3;
	}
	
	// right rotate
	if(caseNo == 1) {
		struct node* t0 = x->left;
		struct node* t1 = x->right;
		struct node* t2 = y->right;
		struct node* t3 = z->right;
		
		// swap values and pointers
		struct node tmp = *b;
		*b = *z;
		*z = tmp;
		struct node* temp = b;
		b = z;
		z = temp;
		
		b->left = a;
		b->right = c;
		a->left = t0;
		a->right = t1;
		c->left = t2;
		c->right = t3;
	}
	return b;
}
