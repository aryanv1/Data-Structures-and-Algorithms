#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(TreeNode* root, int lev, vector<int> &ans)
{
	if(root == NULL)
		return ;
	if(ans.size() == lev) ans.push_back(root->val);
	solve(root->right,lev+1,ans); // for left view call for left side first and then for right
	solve(root->left,lev+1,ans);
}

vector<int> rightSideView(TreeNode* root)
{
	vector<int> ans;
	solve(root,0,ans);
	return ans;
}

int main()
{
	
	return 0;
}