#include <bits/stdc++.h>
using namespace std;
#define ll long long int

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if(root == NULL)
		return NULL;
	if(root == p || root == q) return root;
	TreeNode *left = lowestCommonAncestor(root->left,p,q);
	TreeNode *right = lowestCommonAncestor(root->right,p,q);
	if(!left) return right;
	else if(!right) return left;
	else return root; //left and right both NULL then we found our result
}

int main()
{
	
	return 0;
}