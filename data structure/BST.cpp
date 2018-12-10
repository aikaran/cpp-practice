#include <iostream>
#include <iomanip>
using namespace std;

typedef int key_t;
typedef int val_t;
struct myNode {
	#define WIDTH 3
	key_t key;
	val_t val;
	myNode *left;
	myNode *right;
	myNode(void) : key(0), val(0), left(NULL), right(NULL) {}
	myNode(key_t _key, val_t _val) : key(_key), val(_val), left(NULL), right(NULL) {}
	myNode(key_t _key, val_t _val, myNode* _left, myNode *_right) : key(_key), val(_val), left(_left), right(_right) {}
	friend ostream& operator<<(ostream& os, const myNode *node) {
		os << "(" << setw(WIDTH) << node->key << ", " << setw(WIDTH) << node->val << setw(WIDTH) << ")" << endl;
		return os;
	}
	ostream& inorderPrint(ostream& os, size_t depth) const {
		if(left  != NULL) {
			 left->inorderPrint(os, depth+1);
		}
		for(size_t i=0; i<depth; ++i) {
			os << "\t";
		}
		os << this;
		if(right != NULL) {
			right->inorderPrint(os, depth+1);
		}
		return os;
	}
};

typedef myNode node_t;
class myBST {
private:
	node_t *root;
private:
	static bool insert(node_t *&node, node_t *newNode) {
		if(node == NULL) {
			node = newNode;
			return true;
		}
		else if(node->key    < newNode->key) {
			return insert(node->right, newNode);
		}
		else if(newNode->key < node->key   ) {
			return insert(node->left , newNode);
		}
		return false;
	}
	
	static node_t *findMin(node_t *currentNode) {
		while(currentNode->left != NULL) {
			currentNode = currentNode->left;
		}
		return currentNode;
	}
	
	static node_t *getParentNode(node_t *refNode, node_t *targetNode) {
		if(refNode->left == targetNode || refNode->right == targetNode) {
			return refNode;
		}
		
		if(refNode->key < targetNode->key)
			return getParentNode(refNode->right, targetNode);
		else
			return getParentNode(refNode->left , targetNode);
	}
	
	static void linkNode(node_t *parentNode, node_t *midNode, node_t *childNode) {
		if(parentNode->left == midNode)
			parentNode->left  = childNode;
		else
			parentNode->right = childNode;
		delete midNode;
	}
	
	bool remove(node_t *&node, key_t key) {
		if(node->key < key) {
			if(node->right == NULL) {
				return false;
			}
			return remove(node->right, key);
		}
		if(node->key > key) {
			if(node->left == NULL) {
				return false;
			}
			return remove(node->left , key);
		}
		
		if(node->left != NULL && node->right != NULL) {
			node_t *nextNode = findMin(node->right);
			node->key = nextNode->key;
			node->val = nextNode->val;
			return remove(nextNode, nextNode->key);
		}
		else if(node->left  != NULL) {
			linkNode(getParentNode(root, node), node, node->left );
		}
		else if(node->right != NULL) {
			linkNode(getParentNode(root, node), node, node->right);
		}
		else {
			linkNode(getParentNode(root, node), node, NULL       );
		}
		return true;
	}
public:
	myBST(void) : root(NULL) {}
	
	bool insert(node_t *newNode) {
		if(root == NULL) {
			root = newNode;
			return true;
		}
		else if(root->key    < newNode->key) {
			return insert(root->right, newNode);
		}
		else if(newNode->key < root->key   ) {
			return insert(root->left , newNode);
		}
		return false;
	}
	
	bool insert(key_t newKey, val_t newVal) {
		node_t *newNode = new node_t(newKey, newVal);
		return insert(newNode);
	}
	
	bool remove(key_t key) {
		if(root == NULL) {
			return false;
		}
		else if(root->key <  key) {
			if(root->right != NULL) {
				return remove(root->right, key);
			}
		}
		else if(root->key >  key) {
			if(root->left != NULL) {
				return remove(root->left , key);
			}
		} 
		else {
			return remove(root, key);
		}
		return false;
	}
	
	friend ostream& operator<<(ostream& os, const myBST &BST) {
		BST.root->inorderPrint(os, 0);
		return os;
	}
};
typedef myBST BST_t;

int main(void) {
	BST_t BST;
	BST.insert(4, 9);
	BST.insert(5, 1);
	BST.insert(3, 3);
	BST.insert(1, 6);
	BST.insert(2, 8);
	cout << "INSERT" << endl;
	cout << BST << endl;
	
	BST.remove(4);
	BST.remove(2);
	cout << "DELETE" << endl;
	cout << BST << endl;
	
	return 0;
}
