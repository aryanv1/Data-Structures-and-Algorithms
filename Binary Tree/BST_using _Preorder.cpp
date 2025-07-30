#include <bits/stdc++.h>
using namespace std;
#define ll long long int

TreeNode* solve(int &ind, vector<int>& preorder, int bound) {
	if(ind == preorder.size() || preorder[ind] > bound) 
		return NULL;

	TreeNode *node = new TreeNode(preorder[ind++]);
	node->left = solve(ind,preorder,node->val);
	node->right = solve(ind,preorder,bound);
	return node;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
	int i=0;
	return solve(i, preorder, INT_MAX);
}

int main()
{
	
	return 0;
}