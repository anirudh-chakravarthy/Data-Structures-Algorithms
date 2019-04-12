#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"


struct node* createTree() {
	struct node* root = (struct node*) malloc(sizeof(struct node));
	root->count = 0;
	root->children = (struct node**) malloc(sizeof(struct node*));
	return root;
}


struct node* readData(FILE* f, struct node* root) {
	int choice;
	fscanf(f, "%d ", &choice);

	if(choice == -1)
		exit(0);

	else if(choice == 1) {
		int num_records;
		fscanf(f, "%d\n", &num_records);
		char name[30];
		char ip[30];

		for(int i = 0; i < num_records; i++) {
			fscanf(f, "%s %s\n", name, ip);
			root = insert(root, name, ip);
		}
		
	}

	else if(choice == 2) {
		char name[30];
		fscanf(f, "%s\n", name);
		lookup(root, name);
	}

	return root;
}


struct node* insert(struct node* root, char name[30], char ip[30]) {
	char* tokens[15]; // list of tokens
	int num_tokens = 0;
	printf("Website: %s, IP: %s\n", name, ip);

	for(int i = 0; i < 15; i++)
		tokens[i] = NULL;

	// tokenize the name with '.' as delimiting character
	char* token = strtok(name, ".");
	while(token != NULL) {
		tokens[num_tokens] = (char*) malloc(sizeof(char) * strlen(token));
		printf("%s\n", token);
		strcpy(tokens[num_tokens], token);
		num_tokens++;
		token = strtok(NULL, ".");
	}

	struct node* tmp = root;
	int index = num_tokens - 1;
	int flag = 0; // indicates if node with same key found

	while(tmp != NULL) {		
		
		// insert leaf node
		if(index == 0) {
			struct node* leaf = (struct node*) malloc(sizeof(struct node));
			strcpy(leaf->key, ip);
			leaf->count = 0;
			leaf->children = NULL;
			printf("Inserted: %s\n", leaf->key);

			tmp->children[tmp->count] = leaf;
			tmp->count++;
			return root;
		}

		// iterate over each child node
		for(int i = 0; i < tmp->count; i++) {
			flag = 0;
			// printf("Iteration: %d\t\t", i);
			if(strcmp(tmp->children[i]->key, tokens[index]) == 0) {
				index--;
				tmp = tmp->children[i];
				flag = 1;
				printf("Key: %s found\n", tokens[index]);
				break;
			}
		}

		// not found among children nodes
		if(!flag)
			break;
	}

	// insert remaining tokens in the tree
	while(index >= 0) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		strcpy(newNode->key, tokens[index]);
		newNode->count = 0;
		newNode->children = (struct node**) malloc(sizeof(struct node*));
		index--;
		printf("Inserted: %s\n", newNode->key);

		tmp->children[tmp->count] = newNode;
		tmp->count++;
		tmp = newNode;
	}

	// insert leaf node
	struct node* leaf = (struct node*) malloc(sizeof(struct node));
	strcpy(leaf->key, ip);
	leaf->children = NULL;
	leaf->count = 0;
	printf("Inserted: %s\n", leaf->key);

 	tmp->children[tmp->count] = leaf;
	tmp->count++;
	return root;
}


void lookup(struct node* root, char* name) {
	char* tokens[15]; // list of tokens
	int num_tokens = 0;

	for(int i = 0; i < 15; i++)
		tokens[i] = NULL;

	// tokenize the name with '.' as delimiting character
	char* token = strtok(name, ".");
	while(token != NULL) {
		tokens[num_tokens] = (char*) malloc(sizeof(char) * strlen(token));
		printf("%s\n", token);
		strcpy(tokens[num_tokens], token);
		num_tokens++;
		token = strtok(NULL, ".");
	}

	struct node* tmp = root;
	int index = num_tokens - 1;
	int flag = 0; // indicates if node with same key found

	while(tmp != NULL) {

		// if leaf node is reached
		if(index < 0) {

			// print all IP addresses
			for(int i = 0; i < tmp->count; i++) 
				printf("%s ", tmp->children[i]->key);
			
			printf("\n");
			return;
		}

		// search in children nodes
		for(int i = 0; i < tmp->count; i++) {
			flag = 0; // reset previous value
			if(strcmp(tmp->children[i]->key, tokens[index]) == 0) {
				index--;
				tmp = tmp->children[i];
				flag = 1;
				printf("%d ", i);
				break;
		}
	}

		// not found among children nodes
		if(!flag)
			break;
	}

	printf("Not found\n");
	return;
}
