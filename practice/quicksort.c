#include <stdio.h>


void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}


int partition(int* arr, int start, int pivotIndex) {
	int pivot = arr[pivotIndex];
	int i = start - 1; // iterate over lower elements over arr

	for(int j = start; j < pivotIndex; j++) {
		if(arr[j] <= pivot) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, pivotIndex);
	return i + 1;
}


int hoare_partition(int* arr, int start, int pivotIndex) {
	int pivot = arr[pivotIndex];
	int i = start;
	int j = pivotIndex;

	while(1) {
		
		while(arr[j] >= pivot)
			j--;

		while(arr[i] <= pivot)
			i++;

		if(i < j)
			swap(arr, i, j);
		
		else 
			return j;
	}
}


void quickSort(int* arr, int start, int pivotIndex) {
	if(start < pivotIndex) {
		int mid = partition(arr, start, pivotIndex);
		quickSort(arr, start, mid - 1);
		quickSort(arr, mid, pivotIndex);
	}
}


int main() {
	int arr[10] = {3,2,1,5,4,6,8,7,10,9};
	quickSort(arr, 0, 9);

	for(int i = 0; i < 10; i++) 
		printf("%d ", arr[i]);

	printf("\n");
}