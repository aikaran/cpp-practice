#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > rhombus_t;

vector< vector<char> > makeRhombus(int r, int c) {
	if(r <= 0 || c <= 0)
		return rhombus_t();
	if(r%2 == 0)
		r--;
	rhombus_t rhombus(r, vector<char>(c, ' '));
	char begC = 'A';
	char endC = begC + 2*r - 3;
	size_t i;
	for(i=0; i<=r/2; ++i) {
		if(i!=0) {
			rhombus[i][c/2 - i] = begC++;
			rhombus[i][c/2 + i] = endC--;
		}
		else {
			rhombus[i][c/2] = begC++;
		}
	}
	const int MAX = r-1;
	for(; i<r; ++i) {
		if(i!=MAX) {
			rhombus[i][c/2 - (MAX - i)] = begC++;
			rhombus[i][c/2 + (MAX - i)] = endC--;
		}
		else {
			rhombus[i][c/2] = begC++;
		}
	}
	return rhombus;
}

ostream& printRhombus(ostream& os, const rhombus_t& rhombus) {
	for(size_t r=0; r<rhombus.size(); ++r) {
		for(size_t c=0; c<rhombus[r].size(); ++c) {
			os << rhombus[r][c];
		}
		os << endl;
	}
	os << endl;
	return os;
}

int main(void) {
	int r, c;
	cout << "Enter Row & Col" << endl;
	cin >> r >> c;
	printRhombus(cout, makeRhombus(r, c));
	return 0;
}
