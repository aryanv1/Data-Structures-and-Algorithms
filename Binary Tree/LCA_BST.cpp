#include <bits/stdc++.h>
using namespace std;
#define ll long long int

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root == NULL)
		return NULL;

	int curr = root->val;

	if(p->val > curr && q->val > curr)
		return lowestCommonAncestor(root->right,p,q);

	if(p->val < curr && q->val < curr)
		return lowestCommonAncestor(root->left,p,q);

	return root;
}

int main()
{
	
	return 0;
}