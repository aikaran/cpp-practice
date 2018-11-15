#include <iostream>
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
		return a->freq < b->freq;
	}
};

struct huffmanNode *huffmanCoding(priority_queue<huffmanNode *, vector<huffmanNode *>, huffmanNodeComp>& myQ) {
	int n = myQ.size();
	for(size_t i=0; i<n; ++i) {
		huffmanNode *newNode = new huffmanNode();
		newNode->left = myQ.top();
		myQ.pop();
		newNode->right = myQ.top();
		myQ.pop();
		newNode->freq = newNode->left->freq + newNode->right->freq;
		myQ.push(newNode);
	}
	struct huffmanNode *retNode = myQ.top();
	myQ.pop();
	return retNode;
}

void printHuffman(struct huffmanNode *node) {
	if(node->left != NULL) {
		printHuffman(node->left);
	}
	if(node->right != NULL)
		printHuffman(node->right);
	if(node->ch != 0)
		cout << node->ch << endl;
}

int main(void) {
	priority_queue<huffmanNode *, vector<huffmanNode *>, huffmanNodeComp> myQ;
	huffmanNode * huffAry = new huffmanNode[5];
	huffAry[0].ch = 'a', huffAry[0].freq = 8;
	huffAry[1].ch = 'b', huffAry[1].freq = 5;
	huffAry[2].ch = 'c', huffAry[2].freq = 2;
	huffAry[3].ch = 'd', huffAry[3].freq = 7;
	huffAry[4].ch = 'e', huffAry[4].freq = 3;
	
	for(size_t i=0; i<5; ++i) {
		myQ.push(&huffAry[i]);
	}
	printHuffman(huffmanCoding(myQ));
	return 0;
}
