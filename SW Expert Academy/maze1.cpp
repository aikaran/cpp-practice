#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define TEST_NUM 10
#define ROW 16
#define COL 16
#define START '2'
#define GOAL  '3'
#define ROAD  '0'

typedef vector< vector<char> > map_t;
typedef vector< vector<bool> > visited_t;
typedef queue< pair< int, int> > nextVisit_t;

ostream& printPair(ostream& os, const pair<int, int>& point) {
	os << "(" << point.first << ", " << point.second << ")" << endl;
	return os;
}

istream& getInput(istream& is, map_t& map) {
	for(size_t r=0; r<ROW; ++r) 
		for(size_t c=0; c<COL; ++c) 
			is >> map[r][c];
	return is;
}

pair<int, int> find(const map_t& map, int target) {
	pair< int, int > retv(0, 0);
	for(size_t r=0; r<ROW; ++r)
		for(size_t c=0; c<COL; ++c)
			if(map[r][c] == target) {
				retv.first  = r;
				retv.second = c;
				return retv;
			}
	return retv;
}

void makeNextVisit(nextVisit_t& nextVisit, const map_t& map, const visited_t& visited, int r, int c) {
	if(0 <= r && r <= ROW && 0 <= c && c <= COL && (map[r][c] == ROAD || map[r][c] == GOAL) && visited[r][c] != true)
		nextVisit.push(make_pair(r, c));
}

int main(void) {
	for(size_t test_case = 1; test_case <= TEST_NUM; ++test_case) {
		map_t map(        ROW,  vector<char>(COL, ROAD));
		visited_t visited(ROW, vector<bool>(COL, false));
		nextVisit_t nextVisit;
		size_t answer = 0;
		cin >> test_case;
		getInput(cin, map);
		
		pair< int, int > start = find(map, START);
		//printPair(cout, start);
		pair< int, int >  goal = find(map, GOAL);
		//printPair(cout, goal);
		// is there a path from start to goal?
		nextVisit.push(start);
		while(!nextVisit.empty()) {
			pair<int, int> now = nextVisit.front();
			nextVisit.pop();
			visited[now.first][now.second] = true;
			if( map[now.first][now.second] == GOAL) {
				answer = 1;
				break;
			}	
			//printPair(cout, now);
			// left
			makeNextVisit(nextVisit, map, visited, now.first-1, now.second  );
			// right
			makeNextVisit(nextVisit, map, visited, now.first+1, now.second  );
			// up
			makeNextVisit(nextVisit, map, visited, now.first  , now.second-1);
			// down
			makeNextVisit(nextVisit, map, visited, now.first  , now.second+1);			
		}
		// print answer 
		cout << "#" << test_case << " " << answer << endl;
	}
	
	return 0;
}
