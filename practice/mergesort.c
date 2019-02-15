#include<stdio.h>

void merge(int*, int, int, int);
void mergesort(int*, int, int);


int main() {
	int arr[10] = {1,3,2,4,6,5,8,9,7,10};
	mergesort(arr, 0, 10);
	// int brr[10] = {1,3,5,7,9,2,4,6,8,12};
	// merge(brr, 0, 4, 9);
	for(int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void mergesort(int* arr, int start, int end) {
	int mid = (start + end) / 2;
	if (mid != 0) {
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}


/*
(start to mid) AND (mid+1 to end) are sorted respectively
*/
void merge(int* arr, int start, int mid, int end) {
	int size = end - start + 1;
	int brr[size];

	int i = 0, j = mid + 1;
	int size1 = mid - start + 1;
	int size2 = end - mid;

	for(int idx = 0; idx < size; idx++) {
		if(i == mid) {
			while(j != end) {
				brr[idx] = arr[j];
				j++;
			}
		}
		else if(j == end) {
			while(i != mid) {
				brr[idx] = arr[i];
				i++;
			}
		}
		else if(arr[i] > arr[j]) {
			brr[idx] = arr[j];
			j++;
		}
		else if(arr[i] < arr[j]) {
			brr[idx] = arr[i];
			i++;
		}
		else if(arr[i] == arr[j]) {
			brr[idx] = arr[i];
			idx++; i++;
			brr[idx] = arr[j];
			j++;
		}
	}
	arr = brr;
}