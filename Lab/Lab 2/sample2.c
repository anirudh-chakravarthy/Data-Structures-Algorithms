#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	FILE *fptr = fopen("program.txt", "r");

	if(fptr == NULL) {
		printf("Error! opening file");
		// Program exits if the file pointer returns NULL.
		exit(1);
	}

	fscanf(fptr, "%d", &num);

	printf("Value of n=%d\n", num);
	fclose(fptr);
	 
}
