#include <stdio.h>


int* countingSort(int* arr, int range, int size) {
	int auxilliary[range]; // to count cummulative frequency of entries of each element
	int output[size]; // to store the output array

	// initialize auxilliary storage
	for(int i = 0; i < range; i++)
		auxilliary[i] = 0;

	for(int i = 0; i < size; i++)  
		auxilliary[arr[i]] += 1;

	// store cummulative frequency
	for(int i = 1; i < range; i++)
		auxilliary[i] += auxilliary[i-1];

	for(int i = size - 1; i > -1; i--) {
		output[auxilliary[arr[i]-1]] = arr[i];
		auxilliary[arr[i]] -= 1;
	} 
	return output;
}


int main() {
	int arr[5] = {3,1,10,7,4};
	int* output = countingSort(arr, 10, 5);

	for(int i = 0; i < 5; i++) 
		printf("%d ", output[i]);
	printf("\n");
}