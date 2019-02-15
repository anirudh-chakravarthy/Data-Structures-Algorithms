#include <stdio.h>


// return left node index
int left(int idx) {
	return 2 * idx + 1;
}


// return right node index
int right(int idx) {
	return 2 * idx + 2;
}


// convert an sub-tree to a heap
void max_heapify(int* arr, int rootidx, int size) {
	int l = left(rootidx);
	int r = right(rootidx);
	int max = rootidx;
	if(l < size && arr[max] < arr[l])
		max = l; 
	if(r < size && arr[max] < arr[r]) 
		max = r;
	if(max != rootidx) {
		int tmp = arr[rootidx];
		arr[rootidx] = arr[max];
		arr[max] = tmp;
		max_heapify(arr, max, size);
	}
}


// convert an array into a heap
void build_max_heap(int* arr, int size) {
	for(int i = (size-1) / 2; i >= 0; i--) 
		max_heapify(arr, i, size);
}


void heap_sort(int* arr, int size) {
	build_max_heap(arr, size);
	//int brr[size];
	for(int i = size-1; i > 0; i--) {
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		build_max_heap(arr, i);
	}
}


// extract maximum element
int heap_extract_max(int* arr, int size) {
	if(size < 1) {
		printf("Underflow\n");
		return -1;
	}

	int max = arr[0];
	arr[0] = arr[size-1];
	max_heapify(arr, 0, size-1);
	return max;
}


// increase key at a given index
void heap_increase_key(int*arr, int index, int key, int size) {
	if(key < arr[index]) {
		printf("New key has to be greater than existing key\n");
		return;
	}

	arr[index] = key;
	max_heapify(arr, 0, size);
}


int main() {
	int arr[10] = {1,3,2,4,6,5,8,7,9,10};
	build_max_heap(arr, 10);
	heap_increase_key(arr, 2, 11, 10);
	heap_sort(arr, 10);
	
	for(int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// printf("Max Element: %d\n", heap_extract_max(arr, 10));

}