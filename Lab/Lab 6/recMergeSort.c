#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "merge.h"

#define SIZE 10240


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
	if(start < end) {
		int mid = (start + end) / 2;

		int size1 = mid - start + 1;
		int size2 = end - mid;

		mergeSort(list, start, mid); // on fist half of array
		mergeSort(list, mid+1, end); // on second half

		// store merged array temporarily in result
		Element* result = (Element*) malloc(sizeof(Element) * (size1+size2));
		merge(list+start, size1, list+mid+1, size2, result);

		for(int i = 0; i < size1+size2; i++) {
			list[i+start] = result[i];
		}

		free(result);
	}	
}


int main() {
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);

	Element* list = (Element*) malloc(sizeof(Element) * SIZE);

	FILE* fp = fopen("10240.txt", "r");
	char name[11];
	float cgpa;
	int index = 0;

	// to read input and load it into the structure
	while(fscanf(fp, "%[^,],%f\n", name, &cgpa) != EOF) {
		strcpy(list[index].name, name);
		list[index].cgpa = cgpa;
		index++;
	}

	mergeSort(list, 0, SIZE);
	// printList(list, SIZE);

	fclose(fp);

	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;  // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	printf("Total time is %lf ms.\n", elapsedTime);
	return 0;
}