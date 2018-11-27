#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define TEST_NUM 10
typedef vector<char> completeTree_t;
typedef char val_t;

ostream& printAnswer(ostream& os, const completeTree_t& completeTree, size_t index) {
	size_t left  = index * 2;
	size_t right = index * 2 + 1;
	size_t max   = completeTree.size();
	if( left  < max )
		printAnswer(os, completeTree, left);
	os << completeTree[index];
	if( right < max )
		printAnswer(os, completeTree, right);
	return os;
}

int main(void) {
	for(size_t test_case = 1; test_case <= TEST_NUM; ++test_case) {
		size_t N, index;
		val_t val;
		istringstream iss;
		string line;
		
		// get input
		cin >> N;
		getline(cin, line);
		completeTree_t completeTree(N+1);
		for(size_t i=0; i<N; ++i) {
			getline(cin, line);
			iss.str(line);
			iss >> index >> val;
			
			completeTree[index] = val;
		}
			
		//print answer 
		cout << "#" << test_case << " ";
		printAnswer(cout, completeTree, 1);
		cout << endl;
	}
	return 0;
}
