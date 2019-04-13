#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"


struct node* createTree() {
	struct node* root = (struct node*) malloc(sizeof(struct node));
	root->num_children = 0;
	root->children = (struct node**) malloc(sizeof(struct node*));
	return root;
}


struct node* readData(FILE* f, struct node* root) {
	int count;
	fscanf(f, "%d\n", &count);

	for(int i = 0; i < count; i++) {
		char name[30];
		char ip[30];
		fscanf(f, "%s %s\n", name, ip);
		root = insert(root, name, ip);
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
	int flag = 0;

	while(tmp != NULL) {

		if(index == 0) {
			struct node* newNode = (struct node*) malloc(sizeof(struct node*));
			strcpy(newNode->key, ip);
			newNode->children = (struct node**) malloc(sizeof(struct node*));
			newNode->num_children = 0;
			printf("Inserted: %s\n", ip);

			tmp->num_children++;
			tmp->children = (struct node**) realloc(tmp->children, sizeof(struct node*) * tmp->num_children);
			tmp->children[tmp->num_children-1] = newNode;
			return root;
		}

		for(int i = 0; i < tmp->num_children; i++) {
			flag = 0;
			if(strcmp(tmp->children[i]->key, tokens[index]) == 0) {
				index--;
				tmp = tmp->children[i];
				flag = 1;
				break;
			}
		}

		// not found
		if(!flag)
			break;
	}

	while(index >= 0) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		strcpy(newNode->key, tokens[index]);
		printf("Inserted: %s\n", tokens[index]);
		newNode->children = (struct node**) malloc(sizeof(struct node*));
		newNode->num_children = 0;
		index--;

		tmp->num_children++;
		tmp->children = (struct node**) realloc(tmp->children, sizeof(struct node*) * tmp->num_children);
		tmp->children[tmp->num_children-1] = newNode;
		tmp = newNode;
	}

	struct node* leaf = (struct node*) malloc(sizeof(struct node));
	strcpy(leaf->key, ip);
	leaf->children = NULL;
	leaf->num_children = 0;
	printf("Inserted: %s\n", ip);

	tmp->num_children++;
	tmp->children = (struct node**) realloc(tmp->children, sizeof(struct node*) * tmp->num_children);
	tmp->children[tmp->num_children-1] = leaf;
	return root;
}


void lookup(struct node* root, char name[30]) {
	char* tokens[15]; // list of tokens
	int num_tokens = 0;

	for(int i = 0; i < 15; i++)
		tokens[i] = NULL;

	// tokenize the name with '.' as delimiting character
	char* token = strtok(name, ".");
	while(token != NULL) {
		tokens[num_tokens] = (char*) malloc(sizeof(char) * strlen(token));
		// printf("%s\n", token);
		strcpy(tokens[num_tokens], token);
		num_tokens++;
		token = strtok(NULL, ".");
	}

	struct node* tmp = root;
	int index = num_tokens - 1; 
	int flag = 0;

	while(tmp != NULL) {
		
		// print ip address
		if(index < 0) {
			for(int i = 0; i < tmp->num_children; i++)
				printf("%s", tmp->children[i]->key);
			printf("\n");
			return;
		}

		for(int i = 0; i < tmp->num_children; i++) {
			flag = 0;
			if(strcmp(tmp->children[i]->key, tokens[index]) == 0) {
				printf("%d ", i);
				index--;
				tmp = tmp->children[i];
				flag = 1;
				break;
			}
		}

		if(!flag)
			break;
	}

	printf("Not found!\n");
	return;
}