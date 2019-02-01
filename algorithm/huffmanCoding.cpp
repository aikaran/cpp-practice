#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct huffmanNode {
	char ch;
	int freq;
	struct huffmanNode *left;
	struct huffmanNode *right;
	huffmanNode(void) : ch(0), freq(0), left(NULL), right(NULL) {}
	huffmanNode(char _ch, int _freq) : ch(_ch), freq(_freq), left(NULL), right(NULL) {}
};

struct huffmanNodeComp {
	bool operator()(const huffmanNode *a, const huffmanNode *b) const {
		return a->freq > b->freq || a->freq == b->freq && a->ch;
	}
};

struct huffmanNode *huffmanCoding(priority_queue<huffmanNode *, vector<huffmanNode *>, huffmanNodeComp>& myQ) {
	int n = myQ.size();
	for(size_t i=0; i<n-1; ++i) {
		huffmanNode *newNode = new huffmanNode();
		newNode->left = myQ.top();
		myQ.pop();
		newNode->right = myQ.top();
		myQ.pop();
		newNode->freq = newNode->left->freq + newNode->right->freq;
		cout << "left : " << setw(2) << newNode->left->freq << ", " << newNode->left->ch 
		<< " right : " << setw(2) << newNode->right->freq << ", " << newNode->right->ch << " frequency : " << newNode->freq << endl;
		myQ.push(newNode);
	}
	struct huffmanNode *retNode = myQ.top();
	myQ.pop();
	return retNode;
}

void printHuffman(const struct huffmanNode *node) {
	if(node == NULL)
		return;
	if(node->left != NULL)  {
		cout << "go left" << endl;
		printHuffman(node->left);
	}
	if(node->ch != 0)
		cout << node->ch << endl;
	if(node->right != NULL) {
		cout << "go right" << endl;
		printHuffman(node->right);
	}
	cout << "go up" << endl;
}

int main(void) {
	priority_queue<huffmanNode *, vector<huffmanNode *>, huffmanNodeComp> myQ;
	huffmanNode * huffAry = new huffmanNode[6];
	huffAry[0].ch = 'f', huffAry[0].freq = 5;
	huffAry[1].ch = 'e', huffAry[1].freq = 9;
	huffAry[2].ch = 'c', huffAry[2].freq = 12;
	huffAry[3].ch = 'b', huffAry[3].freq = 13;
	huffAry[4].ch = 'd', huffAry[4].freq = 16;
	huffAry[5].ch = 'a', huffAry[5].freq = 45;
	
	for(size_t i=0; i<6; ++i) {
		myQ.push(huffAry+i);
	}
	printHuffman(huffmanCoding(myQ));
	return 0;
}
