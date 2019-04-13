#ifndef _CHAIN
#define _CHAIN


struct node {
	int key;
	struct node* next;
	int count;
};


typedef struct {
	struct node** head;
	int elementCount;
	int insertionCost;
	int queryingCost;
} table;


// create new Table
table* createTable();

// insert string into table t
table* insert(table* t, char** books, char* string, int index);

// enter strings in books into t
int insertAll(table* t, char** books, int num_strings);

// search for string in table t
struct node* lookup(table* t, char** books, char* string);

// search for percent * num_strings of strings in table t
int lookupAll(table* t, char** books, char** strings, int num_strings, double percent);

// delete occurrence of words in a file from the table
table* cleanup(FILE* f, table* t, char** books);

#endif