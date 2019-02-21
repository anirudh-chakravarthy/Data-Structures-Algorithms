#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

#define K 64


void sort(FILE* f) {
	FILE* fout = fopen("tmp.txt", "w");

	Element* list = (Element*) malloc(sizeof(Element)*K)

	for(int i = 0; i < K; i++) {
		if(!feof(f))
			fscanf(f1, "%[^,],%f\n", list[i].name, &list[i].cg1);
	}

	mergeSort(list, 0, K);
	
	for(int i = 0; i < K; i++) 
		fprintf(fout, "%s,%f\n", list[i].name, list[i].cgpa);

	fclose(f);
	fclose(fout);
}


void mergeFiles(FILE* f1, FILE* f2) {
	FILE* fout = fopen("sorted.txt", "w");

	float cg1, cg2;
	char name1[11], name2[11];

	while(!feof(f1) && !feof(f2)) {
		fscanf(f1, "%[^,],%f\n", name1, cg1);
		fscanf(f2, "%[^,],%f\n", name2, cg2);

		if(cg1 >= cg2) 
			fprintf(fout, "%s,%f\n", name2, cg2);

		else 
			fprintf(fout, "%s,%f\n", name1, cg1);
	}

	while(!feof(f2)) {
		fscanf(f2, "%[^,],%f\n", name2, cg2);
		fprintf(fout, "%s,%f\n", name2, cg2);
	}

	while(!feof(f1)) {
		fscanf(f1, "%[^,],%f\n", name1, cg1);
		fprintf(fout, "%s,%f\n", name1, cg1);
	} 

	fclose(f1);
	fclose(f2);
	fclose(fout);
}


