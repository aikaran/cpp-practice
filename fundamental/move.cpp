#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

typedef int elem_t;

void moveForward(vector<elem_t>& vec, size_t dst, size_t src) {
	for(size_t i=src; i<vec.size(); ++i) {
		vec[dst++] = vec[i];
	}
	vec.resize(dst);
}

void moveBackward(vector<elem_t>& vec, size_t dst, size_t src) {
	const size_t dist = dst - src;
	vec.resize(vec.size()+dist);
	for(size_t i=vec.size()-1-dist; i>=dst; --i) {
		vec[i+dist] = vec[i];
	}
	for(size_t i=src; i<src+dist; ++i) {
		vec[i+dist] = vec[i];
	}
}

void move(vector<elem_t>& vec, size_t dst, size_t src) {
	dst < src ? moveForward(vec, dst, src) : moveBackward(vec, dst, src);
}

int main(void) {
	vector<elem_t> vec1 = {0, 1, 2, 3, 4, 5, 6};
	move(vec1, 2, 5);
	copy(vec1.begin(), vec1.end(), ostream_iterator<elem_t>(cout, " "));
	cout << endl;
	vector<elem_t> vec2 = {0, 1, 2, 3, 4, 5, 6};
	move(vec2, 5, 2);
	copy(vec2.begin(), vec2.end(), ostream_iterator<elem_t>(cout, " "));
	return 0;
}
