#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dns.h"


int main() {
	int choice;
	FILE* f = fopen("input.txt", "r");
	fscanf(f, "%d", &choice);
	// printf("%d\n", choice);

	if(choice == 1) {
		int num_records;
		fgetc(f); // remove spacebar
		fscanf(f, "%d\n", &num_records);
		// printf("%d\n", num_records);
		tree* t = readData(f, num_records);
	}
}