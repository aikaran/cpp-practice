#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define TEST_NUM 10
typedef vector<char> completeTree_t;
typedef char val_t;

bool isValid(const completeTree_t& completeTree, size_t index) {
	size_t left  = index * 2;
	size_t right = index * 2 + 1;
	size_t max   = completeTree.size();
	char val     = completeTree[index];
	const bool isOp = val == '+' || val == '-' || val == '*' || val == '/';
	
	if(isOp) {
		if(max <= left || max <= right)
			return false;
		return isValid(completeTree, left) && isValid(completeTree, right);
	}
	else { // number
		if(left < max || right < max)
			return false;
	}
	return true;
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
		cout << "#" << test_case << " " << isValid(completeTree, 1) << endl;
	}
	return 0;
}
