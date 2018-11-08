#include <iostream>
using namespace std;

void insertionSort(int *arr, int len);
template < class C >
ostream& myPrint(ostream& os, C beg, C end) ;

int main(void) {
	int arr[] = {1, 4, 7, 10, 153, 4, 2356, 263, 2543, 32, 632, 17};
	int len = sizeof(arr) / sizeof(*arr);
	
	myPrint(cout, arr, arr+len);
	insertionSort(arr, len);
	myPrint(cout, arr, arr+len);
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

template < class C >
ostream& myPrint(ostream& os, C beg, C end) {
	for(C it = beg; it != end; ++it) {
		os << *it << " ";
	}
	os << endl;
	return os;
}