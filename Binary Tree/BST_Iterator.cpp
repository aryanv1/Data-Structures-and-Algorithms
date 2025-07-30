#include <bits/stdc++.h>
using namespace std;
#define ll long long int

stack<TreeNode *> s;
BSTIterator(TreeNode* root) {
	pushAll(root);
}

int next() {
	TreeNode *ans = s.top();
	s.pop();
	if(ans->right) 
		pushAll(ans->right);
	return ans->val;
}

bool hasNext() {
	return !s.empty();
}

void pushAll(TreeNode *node)
{
	while(node)
	{
		s.push(node);
		node = node->left;
	}
}

int main()
{
	
	return 0;
}

// Time Complexity - O(1)
// Space Complexity - O(N)