#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	priority_queue< int, vector<int>, greater<int> > q1;
	int v1[] = {14, 12, 234, 26, 3, 29, 24, 14};
	int len = sizeof(v1)/sizeof(*v1);
	for(size_t i=0; i<len; ++i) {
		q1.push(v1[i]);
	}
	for(size_t i=0; i<len; ++i) {
		cout << q1.top() << " ";
		q1.pop();
	}
	return 0;
}
