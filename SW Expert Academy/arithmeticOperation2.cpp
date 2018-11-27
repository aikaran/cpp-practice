#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define TEST_NUM 10
#define TREE_MAX 1001
typedef char op_t;
typedef double val_t;
struct elem_t {
	bool isOp;
	val_t val;
	size_t left;
	size_t right;
	elem_t(bool _isOp, val_t _val, size_t _left, size_t _right)
	: isOp(_isOp), val(_val), left(_left), right(_right) {}
};
typedef vector<elem_t> binaryTree_t;

val_t getValue(op_t op, val_t leftValue, val_t rightValue) {
	switch(op) {
	case '+' : return leftValue + rightValue;
	case '-' : return leftValue - rightValue;
	case '*' : return leftValue * rightValue;
	case '/' : return leftValue / rightValue;
	default  : return 0.0;
	}
}

val_t getValue(const binaryTree_t& binaryTree, size_t index) {
	if(binaryTree[index].isOp) {
		return getValue(binaryTree[index].val, getValue(binaryTree, binaryTree[index].left), getValue(binaryTree, binaryTree[index].right));
	}
	else {
		return binaryTree[index].val;
	}
}

int main(void) {
	for(size_t test_case = 1; test_case <= TEST_NUM; ++test_case) {
		binaryTree_t binaryTree(TREE_MAX, elem_t(false, 0.0, 0, 0));
		size_t N, index;
		val_t val;
		op_t op;
		
		// get input
		cin >> N;
		for(size_t i=0; i<N; ++i) {
			cin >> index >> op;
			
			if( '1' <= op && op <= '9') {
				cin.unget();
				cin >> binaryTree[index].val;
			}
			else {
				binaryTree[index].isOp  = true;
				binaryTree[index].val = op;
				cin >> binaryTree[index].left >> binaryTree[index].right;
			}
		}
			
		//print answer 
		cout << "#" << test_case << " " << static_cast<int>(getValue(binaryTree, 1)) << endl;
	}
	return 0;
}

