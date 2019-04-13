#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "chain.h"


int baseNumber = 5023;
int tableSize = 5000;


char** parser(FILE* f) {
	char* book[50000];
	char* word = (char*) malloc(sizeof(char) * 30);
	int num_strings = 0;

	while(fscanf(f, "%s", word) != EOF) {
		fgetc(f);
		int flag = 0; // set if invalid string detected
		for(int i = 0; i < strlen(word); i++) {
			if(!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z'))) {
				flag = 1;
				break;
			}
		}

		if(!flag) {
			num_strings++;
			book[num_strings-1] = (char*) malloc(sizeof(char) * (1+ strlen(word)));
			strcpy(book[num_strings-1], word);
		}
	}
	free(word);
	printf("Number of valid strings: %d\n", num_strings);
	return book;
}


int main() {
	FILE* f = fopen("aliceinwonderland.txt", "r");
	char** book = parser(f);
	printf("Number of collisions: %d\n", collisionCount(book, 22698, baseNumber, tableSize));
	fclose(f);

	Hashtable* h = createTable(tableSize);
	printf("Insertion Cost: %d\n", insertAll(h, book));

	struct node* tmp = lookup(h, book, "to");
	printf("%s\n", book[82]);

	printf("Querying Cost: %d\n", lookupAll(h, book, book, 22698, 0.001));

	f = fopen("stopwords.txt", "r");
	h = cleanup(f, h, book);
	printf("Number of elements: %d\n", h->elementCount);
	fclose(f);

}