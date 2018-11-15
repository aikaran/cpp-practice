#include <iostream>
#include <string>
#include <set>
using namespace std;

struct point {
	int x, y;
	point(void) : x(0), y(0) {}
	point(int _x, int _y) : x(_x), y(_y) {}
	friend ostream& operator<<(ostream& os, const point& p) {
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}
};

struct pointComp {
	bool operator()(const point& a, const point& b) const {
		return a.x < b.x || (a.x == b.x) && a.y < b.y;
	}
};

int main(void) {
	set<point, pointComp> mySet;
	mySet.insert(point(2, 3));
	mySet.insert(point(1, 2));
	for(auto it = mySet.begin(); it!=mySet.end(); ++it) {
		cout << (*it) << endl;
	}
	return 0;
}

