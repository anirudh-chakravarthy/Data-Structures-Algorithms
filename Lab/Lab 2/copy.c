#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	if(argc == 2) {
		printf("Please specify destination file\n");
		exit(1);
	}

	if(argc == 1) {
		printf("please specify src and dst file\n");
		exit(1);
	}

	if(argc > 3) {
		printf("Please enter exactly 1 src and 1 dst file\n");
		exit(1);
	}

	FILE* f1 = fopen(argv[1], "r");
	FILE* f2 = fopen(argv[2], "w");

	if(f1 == NULL) {
		printf("Unable to read from %s\n", argv[1]);
		exit(1);
	}

	if(f2 == NULL) {
		printf("Unable to write to %s\n", argv[2]);
		exit(1);
	}

	char c = fgetc(f1);
	while(c != EOF) {
		fputc(c, f2);
		c = fgetc(f1); 
	}
}
