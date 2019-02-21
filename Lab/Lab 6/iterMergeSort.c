#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge.h"

#define SIZE 1024


void printList(Element ls[], int size) {
	for(int i = 0; i < size; i++) 
		printf("%s %lf\n", ls[i].name, ls[i].cgpa);
}


void merge(Element l1[], int size1, Element l2[], int size2, Element ls[]) {
	int i = 0, j = 0;
	int index = 0;

	int size = size1 + size2;
	
	while(index < size) {

		if(i == size1) {
			ls[index] = l2[j];
			j++;
			index++;
			continue;
		}

		if(j == size2) {
			ls[index] = l1[i];
			i++;
			index++;
			continue;
		}

		if(l1[i].cgpa >= l2[j].cgpa) {
			ls[index] = l2[j];
			j++;
			index++;
			continue;
		}

		if(l1[i].cgpa < l2[j].cgpa) {
			ls[index] = l1[i];
			i++;
			index++;
			continue;
		}
	}

}


void mergeSort(Element list[], int start, int end) {
}


int main() {
	Element* list = (Element*) malloc(sizeof(Element) * SIZE);

	FILE* fp = fopen("1024.txt", "r");
	char name[11];
	float cgpa;
	int index = 0;

	while(fscanf(fp, "%[^,],%f\n", name, &cgpa) != EOF) {
		strcpy(list[index].name, name);
		list[index].cgpa = cgpa;
		index++;
	}

	mergeSort(list, 0, SIZE);
	printList(list, SIZE);
}