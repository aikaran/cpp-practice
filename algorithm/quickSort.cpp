#include <iostream>

using namespace std;

void quickSort(int *, int, int);
template < class C >
ostream& myPrint(ostream& os, C beg, C end) ;

int main(void) {
	int arr[] = {1, 4, 7, 10, 153, 4, 2356, 263, 2543, 32, 632, 17};
	int len = sizeof(arr) / sizeof(*arr);
	
	myPrint(cout, arr, arr+len);
	quickSort(arr, 0, len-1);
	myPrint(cout, arr, arr+len);
	return 0;
}

void quickSort(int *arr, int first, int last) {
	int pivot = arr[(first+last)/2];
	int beg = first, end = last;
	int temp;
	
	do {
		while(arr[beg] < pivot) beg++;
		while(arr[end] > pivot) end--;
		
		if(beg <= end) {
			temp = arr[beg];
			arr[beg] = arr[end];
			arr[end] = temp;
			beg++;
			end--;
		}
	} while(beg <= end) ;
	
	if(first < end)
		quickSort(arr, first, end);
	if(beg < last)
		quickSort(arr, beg, last);
}

template < class C >
ostream& myPrint(ostream& os, C beg, C end) {
	for(C it = beg; it != end; ++it) {
		os << *it << " ";
	}
	os << endl;
	return os;
}
