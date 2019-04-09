#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dns.h"


tree* createTree() {
	tree* t = (tree*) malloc(sizeof(tree));
	return t;
}


tree* insert(tree* t, char* name, char* ip) {
	char* tokens[15]; // list of tokens
	int num_tokens = 0;
	printf("Website: %s, IP: %s\n", name, ip);

	for(int i = 0; i < 15; i++)
		tokens[i] = NULL;

	char* token = strtok(name, ".");
	while(token != NULL) {
		tokens[num_tokens] = (char*) malloc(sizeof(char) *strlen(token));
		printf("%s\n", token);
		strcpy(tokens[num_tokens], token);
		num_tokens++;
		token = strtok(NULL, ".");
	}

	int j = num_tokens - 1;
	if(tmp == NULL) {
		struct node* rootNode = (struct node*) malloc(sizeof(struct node));
		rootNode->count = 0;
		rootNode->children = (struct node**) malloc(sizeof(struct node*));
		t->root = rootNode;
	}

	struct node* tmp = t->root;
	while(tmp != NULL) {
		int flag = 0;
		if(tmp->count == 0) 
		for(int i = 0; i < tmp->count; i++) {
			if (strcmp(tmp->children[i]->key, tokens[j]) == 0) {
				j--;
				tmp = tmp->children[i];
				flag = 1;
				break;
			}
		}
		// no match found
		if(!flag) 
			break;
	}

	while(j >= 0) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		strcpy(newNode->key, tokens[j]);
		newNode->children = (struct node**) malloc(sizeof(struct node*));
		tmp->children[tmp->count] = newNode;
		tmp->count++;
		tmp = newNode;
		j--;

		if(j == 0)
			newNode->count = 0;
		else
			newNode->count = 1;
	}

	// storing ip at leaf node
	struct node* ipNode = (struct node*) malloc(sizeof(struct node));
	strcpy(ipNode->key, ip);
	ipNode->count = 0;

	tmp->children[tmp->count] = ipNode;
	tmp->count++;
	return t;
}


tree* readData(FILE* f, int n) {
	char name[30]; 
	char ip[30];
	tree* t = createTree();

	for (int i = 0; i < n; i++) {
		fscanf(f, "%s %s", name, ip);
		// printf("Website: %s, IP: %s\n", name, ip);
		t = insert(t, name, ip);
	}
	return t;
}