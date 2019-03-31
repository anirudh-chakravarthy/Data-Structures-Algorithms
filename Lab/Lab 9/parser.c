#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #include "hash.h"
#include "parser.h"


char** parser(char* fileName) {
	FILE* f = fopen(fileName, "r");
	int count = 0;
	char* stringList[50000];
	char* string = (char*) malloc(sizeof(char) * 50);

	while(fscanf(f, "%s", string) != EOF) {
		char* tmp = string;
		int length = strlen(string);
		int flag = 0;
		
		for(int i = 0; i < length; i++) {
			if(!((tmp[i] >= 'A' && tmp[i] <= 'Z') || (tmp[i] >= 'a' && tmp[i] <= 'z'))) {
				flag = 1; // if string contains non-alphabet
				break;
			}
		}

		if(!flag) {
			stringList[count] = (char*) malloc(sizeof(char) * strlen(string));
			strcpy(stringList[count], string);
			// printf("%s\n", string);
			count++;
		}
	}

	printf("Number of valid strings are: %d\n", count);
	free(string);

	// profiling to find best parameters
	// int tableSizes[3] = {5000, 50000, 500000};
	// int baseNumbers[9] = {5227, 6911, 9091, 50461, 78017, 88807, 551003, 692071, 800011};
	// int sizeIdx = 0, baseIdx = 0; // store best parameter index

	// int collisions = collisionCount(stringList, 22698, baseNumbers[0], tableSizes[0]);
	// // printf("HERE!");

	// for(int i = 0; i < 3; i++) {
	// 	int j = 0;
	// 	if (collisions < collisionCount(stringList, count, baseNumbers[3*i +j], tableSizes[i])) {
	// 		sizeIdx = i;
	// 		baseIdx = 3*i +j;
	// 	}
	// 	j++;
	// }
	// printf("Base Number Index: %d Table Size Index: %d\n", baseIdx, sizeIdx);
	return stringList;
}
