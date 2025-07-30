#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(TreeNode *root, int &maxi)
{
	if(root == NULL)
		return 0;
    //taking 0 to ignore the negative sum
	int lh = max(0,solve(root->left,maxi));
	int rh = max(0,solve(root->right,maxi));
	maxi = max(maxi,root->val+lh+rh);
	return root->val + max(lh,rh);
}
int maxPathSum(TreeNode* root) {
	int maxi = INT_MIN;
	solve(root,maxi);
	return maxi;
}

int main()
{
	
	return 0;
}