#include <iostream>
#include <list>
using namespace std;

#define TEST_NUM 10
#define PRINT_NUM 10

istream& getInput(istream& is, list<int>& myList) {
	size_t N, val;
	is >> N;
	for(size_t i=0; i<N; ++i) {
		is >> val;
		myList.push_back(val);
	}
	return is;
}

ostream& printAnswer(ostream& os, const list<int>& myList, size_t test_case) {
	os << "#" << test_case << " ";
	auto it = myList.begin();
	for(size_t i=0; i<PRINT_NUM; ++i) {
		os << *it << " ";
		it++;
	}
	os << endl;
	return os;
}

istream& myInsert(istream& is, list<int>& myList) {
	size_t J, M, val;
	list<int> newList;
	is >> J >> M;
	auto it = myList.begin();
	advance(it, J);
	for(size_t j=0; j<M; ++j) {
		is >> val;
		newList.push_back(val);
	}
	myList.splice(it, newList, newList.begin(), newList.end());
	return is;
}

istream& myDelete(istream& is, list<int>& myList) {
	size_t J, M, val;
	list<int> newList;
	is >> J >> M;
	auto it = myList.begin();
	advance(it, J);
	auto it2 = it;
	advance(it2, M);
	newList.splice(newList.begin(), myList, it, it2);
	return is;
}

istream& myAdd(istream& is, list<int>& myList) {
	size_t M, val;
	is >> M;
	for(size_t j=0; j<M; ++j) {
		is >> val;
		myList.push_back(val);
	}
	return is;
}

istream& processCommand(istream& is, list<int>& myList) {
	char cmd;
	is >> cmd;
	switch(cmd) {
	case 'I': myInsert(is, myList); break;
	case 'D': myDelete(is, myList); break;
	case 'A': myAdd(is, myList);    break;
	default : break;
	}
	return is;
}

int main(void) {
	for(size_t test_case = 1; test_case <= TEST_NUM; ++test_case) {
		list<int> myList;
		size_t N;
		
		getInput(cin, myList);
		
		cin >> N;
		for(size_t i=0; i<N; ++i) 
			processCommand(cin, myList);
		
		printAnswer(cout, myList, test_case);	
	}
	return 0;
}
