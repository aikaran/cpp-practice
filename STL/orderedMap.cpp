#include <iostream>
#include <string>
#include <map>
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
	map<point, string, pointComp> myMap;
	myMap[point(1, 2)] = "hi";
	myMap[point(2, 3)] = "i am mincheol";
	for(auto it = myMap.begin(); it!=myMap.end(); ++it) {
		cout << (*it).first << " " << (*it).second << endl;
	}
	return 0;
}
