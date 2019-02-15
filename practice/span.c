#include<stdio.h>


int* span(int* arr, int size) {
	int brr[size];
	brr[0] = 1;
	for(int i = 1; i < size; i++) {
		if(arr[i] > arr[i-1])
			brr[i] = brr[i-1] + 1;
		else 
			brr[i] = 1;
	}
	return brr;
}

int main() {
	int arr[10]  ={1,3,2,8,5,7,11,3,0,10};
	int brr[];
	brr = span(arr, 10);
	for(int i = 0; i < 10; i++) {
		printf("%d ", brr[i]);
	}
	printf("\n");
}

