#include<stdio.h>


void bubblesort(int* arr, int size) {
	for(int iters = 0; iters < size; iters++) {
		int i = 0;
		int j = 1;
		while(i < size - 1) {
			if(arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
			i++;
		}
	}
}


int main() {
	int arr[5] = {5,3,2,1,4};
	bubblesort(arr, 5);

	for(int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}