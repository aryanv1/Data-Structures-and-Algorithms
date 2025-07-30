#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
private:
	vector<int> ans;
public:
	TreeNode* solve(int left, int right, vector<int> &ans)
	{
		if(left > right || right < left)
			return NULL;
		if(left == right)
		{
			return new TreeNode(ans[left]);
		}
		int mid = (left + right)/2;
		TreeNode *t = new TreeNode(ans[mid]);
		t->left = solve(left,mid-1,ans);
		t->right = solve(mid+1,right,ans);

		return t;
	}
	void inorder(TreeNode *root)
	{
		if(root == NULL)
			return ;
		inorder(root->left);
		ans.push_back(root->val);
		inorder(root->right);
	}
	TreeNode* balanceBST(TreeNode* root) {
		inorder(root);
		int n = ans.size();
		return solve(0,n-1,ans);
	}
};

int main()
{
	
	return 0;
}

// Start dividing the tree from middle of the array to get a balances BST