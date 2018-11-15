#include <iostream>

using namespace std;

struct myNode {
	int value;
	struct myNode *next;
	myNode(void) : value(0), next(NULL) {}
	myNode(int val) : value(val), next(NULL) {}
};

struct forwardList {
	struct myNode *head;
	forwardList(void) : head() {}
	struct myNode *push(int val) {
		struct myNode *newNode = new struct myNode(val);
		if(head == NULL)
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
		return newNode;
	}
	struct myNode pop(void) {
		if(head != NULL) {
			struct myNode retNode = *head;
			struct myNode *del = head;
			head = head->next;
			
			delete del;
			return retNode;
		}
		else {
			exit(1);
		}
	}
	struct myNode top(void) {
		if(head != NULL)
			return *head;
		else
			exit(1);
	}
};

int main(void) {
	return 0;
}
