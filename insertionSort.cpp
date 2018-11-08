#include <iostream>

using namespace std;

void insertionSort(int *arr, int len);
void printArray(int *, int);

int main(void) {
	int arr[] = {1, 4, 7, 10, 153, 4, 2356, 263, 2543, 32, 632, 17};
	int len = sizeof(arr) / sizeof(*arr);
	
	printArray(arr, len);
	insertionSort(arr, len);
	printArray(arr, len);
	return 0;
}

void insertionSort(int *arr, int len) {
	int remember;
	for(int i=1, j; i<len; ++i) {
		remember = arr[j=i];
		while(--j >= 0 && remember < arr[j]) {
			arr[j+1] = arr[j];
			arr[j] = remember;
		}
	}
}

void printArray(int *arr, int len) {
	for(size_t i=0; i<len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
