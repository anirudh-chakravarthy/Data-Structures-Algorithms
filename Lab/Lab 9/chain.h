#ifndef _CHAIN
#define _CHAIN


struct node{
	int key;
	int count;
	struct node* next;
};

typedef struct {
	struct node** head;
	int elementCount;
	int insertionCost;
	int queryingCost;
} Hashtable;


// create an empty table
Hashtable* createTable(int tableSize);

// insert string into table t if not already present
Hashtable* insert(Hashtable* t, char** book, int index);

// insert all strings from book into table t
int insertAll(Hashtable* t, char** book);

// search for string
struct node* lookup(Hashtable* t, char** book, char* string);

// search for m*100% of strings in table t
int lookupAll(Hashtable* t, char** book, char** strings, int num_strings, double m);

// delete words from the table
Hashtable* cleanup(FILE* f, Hashtable* t, char** book);


#endif