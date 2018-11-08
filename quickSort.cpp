#include <iostream>

using namespace std;

void quickSort(int *arr, int first, int last) {
	int pivot = arr[ (first+last) / 2];
	int beg = first, end = last;
	int temp;
	do {
		while(arr[beg] < pivot) beg++;
		while(arr[end] > pivot) end--;	
		
		if( beg <= end) {
			temp	 = arr[beg];
			arr[beg] = arr[end];
			arr[end] = temp;
			beg++;
			end--;
		}
			
	} while(beg <= end) ;
	
	
	if(beg  < last)
		quickSort(arr, beg,   last);
	if(first< end)
		quickSort(arr, first, end);
}

void printArray(int *arr, int len) {
	for(size_t i=0; i<len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main(void) {
	int arr[] = {5, 3, 1, 7, 9, 10};
	int len   = sizeof(arr) / sizeof(*arr);
	
	quickSort(arr, 0, len-1);
	printArray(arr, len);
	return 0;
}
