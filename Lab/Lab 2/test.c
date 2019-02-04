#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	if(argc == 1) {
		printf("please enter a word");
		exit(0);
	}
	
	int i = 1;
	while(i < argc) {
		int num = atoi(argv[i]);
		if(num == 0) 
			printf("%s ", argv[i]);
		else
			printf("%d ", num);
		i++;
	}
	printf("\n");
}
