#include <iostream>
#include <string>
#include <unordered_set>
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

struct pointHash {
	size_t operator()(const point& p) const {
		return std::hash<int>()(p.x) ^
            (std::hash<int>()(p.y) << 1);
	}
};

struct pointComp {
	bool operator()(const point& a, const point& b) const {
		return a.x == b.x && a.y == b.y;
	}
};

int main(void) {
	unordered_set<point, pointHash, pointComp> mySet;
	mySet.insert(point(1, 2));
	mySet.insert(point(2, 1));
	return 0;
}
