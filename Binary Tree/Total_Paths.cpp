#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(Node *root,vector<vector<int>> &ans, vector<int> ds)
{
	if(root == NULL) return ;
	ds.push_back(root->data);
	if(!root->left && !root->right)  
	{
		ans.push_back(ds);
		return ;
	}
	if(root->left)
		solve(root->left,ans,ds);
	if(root->right)
		solve(root->right,ans,ds);
    // ds.pop_back(); // every node have their own ds array with elements upto that node so no need of popping back
}
vector<vector<int>> Paths(Node* root) 
{
	vector<vector<int>> ans;
	vector<int> ds;
	solve(root,ans,ds);
	return ans;
}

int main()
{
	
	return 0;
}