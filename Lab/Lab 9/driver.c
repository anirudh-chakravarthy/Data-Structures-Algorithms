#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "chain.h"


// returns percent at which querying cost overtakes insertion cost
double profile(table* t, char** books, int num_strings) {
	for(double i = .1; i <= 2; i += .1) {
		int queryingCost = lookupAll(t, books, books, num_strings, i);
		printf("Insertion Cost: %d, Querying Cost: %d\n", t->insertionCost, queryingCost);

		if(queryingCost >= t->insertionCost) 
			return i;
	}
	return 0.0;
}


int main() {
	FILE* f = fopen("aliceinwonderland.txt", "r");
	char** books = parser(f);
	table* t = createTable();
	fclose(f);

	int num_strings = 22698;
	int insertionCost = insertAll(t, books, num_strings);
	printf("Table Size: %d\n", t->elementCount);
	printf("Insertion Cost: %d\n", insertionCost);

	// struct node* tmp = lookup(t, books, "to");
	// printf("Querying Cost: %d\n", t->queryingCost);

	int queryingCost = lookupAll(t, books, books, num_strings, 0.05);
	printf("Querying Cost: %d\n", queryingCost);

	f = fopen("stopwords.txt", "r");
	t = cleanup(f, t, books);
	printf("Table Size: %d\n", t->elementCount);
	fclose(f);


	double percentage = profile(t, books, num_strings);
	if (percentage == 0.0)
		printf("No Optimal value in the range\n");
	else
		printf("Optimal Percentage Value: %lf\n", percentage); 
}