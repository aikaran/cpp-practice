#include <iostream>
#include <queue>
using namespace std;

#define TEST_NUM 10
#define PW_NUM 8
#define PW_CYCLE 5

istream& getInput(istream& is, queue<int>& myQ) {
	int val;
	for(size_t v=0; v<PW_NUM; ++v) {
		is >> val;
		if(val < 0)
			val = 0;
		myQ.push(val);
	}
	return is;
}

void passwordGenerator(queue<int>& myQ) {
	while(true) {
		for(size_t i=1; i<=PW_CYCLE; ++i) {
			int next = myQ.front();
			next -= i;
			if(next <= 0) {
				next = 0;
				myQ.push(next);
				myQ.pop();
				return;
			}
			else {
				myQ.push(next);
				myQ.pop();
			}
		}
	}
}

ostream& printQueue(ostream& os, queue<int>& myQ, size_t test_case) {
	os << "#" << test_case << " ";
	while(!myQ.empty()) {
		os << myQ.front() << " ";
		myQ.pop();
	}
	os << endl;
	return os;
}

int main(void) {
	for(size_t test_case = 1; test_case <= TEST_NUM; ++test_case) {
		cin >> test_case;
		queue<int> myQ;
		getInput(cin, myQ);
		
		passwordGenerator(myQ);
		
		printQueue(cout, myQ, test_case);	
	}
	return 0;
}
