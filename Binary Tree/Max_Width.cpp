#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int widthOfBinaryTree(TreeNode* root) 
{
	// 0-based indexing -> left=2*i+1 and right=2*i+2
	// 1-based indexing -> left=1*i and right=2*i+1
	if(!root) return 0;
	queue<pair<TreeNode*,long long>> q;
	q.push({root,0});
	int maxi = 1;
	while(!q.empty())
	{
		long long mini = q.front().second;
		int sz = q.size();
		int last;
		for(int i=0; i<sz; i++)
		{
			TreeNode *node = q.front().first;
			long long ind = q.front().second - mini; // To start index of next lev from 0 -> to prevent overflow -> In case of skew trees, this value will becomes so much large so starting from zero
			q.pop();
			// if(i == 0) first = ind;
			if(i == sz-1) last = ind;
			if(node->left)
				q.push({node->left,2*ind+1});
			if(node->right)
				q.push({node->right,2*ind+2});
		}
		maxi = max(maxi,last+1); // 0-based indexing so +1
	}
	return maxi;
}

int main()
{
	
	return 0;
}