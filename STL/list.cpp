#include <iostream>
#include <string>
#include <list>
using namespace std;

ostream& operator<<(ostream& os, const list<string>& myList) {
	for(list<string>::const_iterator it = myList.begin(); it != myList.end(); ++it) {
		os << (*it) << " ";
	}
	os << endl;
	return os;
}

int main(void) {
	list<string> myList;
	myList.push_back("hi");
	myList.push_back("i");
	myList.push_back("am");
	myList.push_back("mincheol");
	
	cout << myList;
	return 0;
}

