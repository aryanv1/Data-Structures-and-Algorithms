#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool solve1(TreeNode *root, TreeNode *left,TreeNode *right)
{
	if(root == NULL)
		return 1;

	if((left == NULL || left->val < root->val) && (right == NULL || right->val > root->val))
		return (solve(root->left,left,root) && solve(root->right,root,right));;

	return 0;
}

bool solve(TreeNode *root, int &left,int &right)
{
	if(root == NULL)
		return 1;

	if(root->val <= left || root->val >= right)
		return 0;

	return (solve(root->left,left,root->val) && solve(root->right,root->val,right));
}
bool isValidBST(TreeNode* root) {
	int left = INT_MIN, right = INT_MAX;
	return solve(root,left,right);

	// return solve1(root,NULL,NULL);
}

int main()
{
	
	return 0;
}