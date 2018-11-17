#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isCan(const vector<int>& vec, const vector<int>&  proposition, const size_t n) {
	vector<size_t> total(n, 0);
	for(size_t i=0; i<vec.size(); ++i) {
		total[proposition[i]] += vec[i];
	}
	for(size_t i=1; i<total.size(); ++i) {
		if(total[i-1] != total[i])
			return false;
	}
	for(int i : proposition)
		cout << i << " ";
	cout << endl;
	for(int i : total)
		cout << i << " ";
	cout << endl;
	return true;
}

void next(vector<int>&  proposition, const size_t n) {
	for(size_t i=0; i<proposition.size(); ++i) {
		if(proposition[i] != n-1) {
			proposition[i]++;
			return;
		}
		else {
			proposition[i] = 0;
		}
	}
}

bool subsetBookshelf(const vector<int>& vec, const size_t n) {
	vector<int> proposition(vec.size(), 0);
	int i = 1;
	for(size_t j=0; j<vec.size(); ++j)
		i *= n;
	for(size_t j=0; j<i; ++j) {
		if(isCan(vec, proposition, n))
			return true;
//		copy(proposition.begin(), proposition.end(), ostream_iterator<int>(cout, " "));
		next(proposition, n);
//		cout << endl;3
	}
	return false;
}

int main(void) {
	vector<int> vec; //= {1, 2, 3, 2, 1};
	size_t b, total = 0;
	srand(time(NULL));
	const int n = 1 + rand() % 9;
	for(int i=0; i<n; ++i) {
		vec.push_back(1 + rand() % 9);
	}
	cout << "Enter book shelf number" << endl;
	cin >> b;
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	for(int i : vec)
		total += i;
	cout << "total : " << total << endl;
	if(total % b)
		cout << "total impossible" << endl;
	else {
		if(subsetBookshelf(vec, b))
			cout << "possible" << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}
