#include <iostream>
#include <string>
#include <unordered_map>
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

int main(void) {
	unordered_map<string, point> myMap;
	myMap["hi"] = point(1, 2);
	myMap["i am mincheol"] = point(2, 3);
	for(const auto& it : myMap) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}
