#include<stdio.h>
#include<stdlib.h>


/* 
INSERTION SORT ALGORITHM
i = element index which you want to insert
j = index to find position for the element
*/
int* insertionsort(int arr[], int length) {
	for(int i = 1; i < length; i++) {
		int j = i - 1;
		int ele = arr[i];
		while(ele < arr[j]) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = ele;
	}
	return arr;
}

int main() {
	int arr[5] = {5,3,2,1,4};
	insertionsort(arr, 5);
	for(int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}