#ifndef _CH
#define _CH


struct node {
	int element;
	int count;
	struct node* next;
};


typedef struct {
	struct node** head;
	int elementCount;
	int insertionCost;
	int queryingCost;
} hashTable;


int hash(char* string, int baseNumber, int tableSize);

hashTable createTable();

int insertAll(hashTable h, char** book, int numberOfStrings);


#endif