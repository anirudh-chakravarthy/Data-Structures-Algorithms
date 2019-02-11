#ifndef _CC
#define _CC

int size, count; 


struct CreditCard {
	long long int cardNo;
	char bankCode[6];
	char expiryDate[8];
	char firstName[25];
	char lastName[25];
};


struct CreditCard* readRecord(FILE* f);

void insertInOrder(struct CreditCard* c, struct CreditCard record, int size);

#endif