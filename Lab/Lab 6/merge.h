#ifndef _MERGE
#define _MERGE
#include <stdio.h>


typedef struct {
	char name[11];
	float cgpa;
} Element;


void merge(Element l1[], int size1, Element l2[], int size2, Element ls[]);

void mergeSort(Element list[], int start, int end);


#endif