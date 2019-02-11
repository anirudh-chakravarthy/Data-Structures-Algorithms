#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creditcard.h"

int size = 10;
int count = 0;


struct CreditCard* readRecord(FILE* f) {

	long long int cardNo;
	char bankCode[6], expiryDate[8];
	char firstName[30], lastName[30];

	struct CreditCard* c = (struct CreditCard*) malloc(sizeof(struct CreditCard) * size);

	while(!feof(f)) {
		fgetc(f);
		fscanf(f, "%lld", &cardNo);
		fscanf(f, ",%[^,],%[^,],%[^,],%[^\"]\"\n", bankCode, expiryDate, firstName, lastName);

		if(count == size - 1) {
			size = size * 2;
			c = realloc(c, sizeof(struct CreditCard) * size);
		}

		c[count].cardNo = cardNo;
		strcpy(c[count].bankCode, bankCode);
		strcpy(c[count].expiryDate, expiryDate);
		strcpy(c[count].firstName, firstName);
		strcpy(c[count].lastName, lastName);
		// printf("%lld\n", c[count].cardNo);
		count++;
	}

	return c; 
}


void insertInOrder(struct CreditCard* c, struct CreditCard record, int size) {
	
	// insert in empty list
	// if(size == 0) {
	// 	c[size] = record;
	// 	// printf("HERE!\n");
	// 	return;
	// }

	// if(size == count - 1) {
	// 	c = realloc(c, 2 * size);
	// }

	int idx = 0;

	while(idx < size && c[idx].cardNo < record.cardNo)
		idx++;

	// inserting at the end
	// if(idx == size - 1) {
	// 	c[idx+1] = record;
	// 	return;
	// }

	int j = size - 1;

	while(j >= idx) {
		c[j+1] = c[j];
		j--;
	}

	// inserting record in the middle
	c[idx] = record;
}
