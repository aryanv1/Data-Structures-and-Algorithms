#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int left_height(Node *root)
{
	int cnt = 0;
	while(root)
	{
		cnt++;
		root = root->left;
	}
	return cnt;
}
int right_height(Node *root)
{
	int cnt = 0;
	while(root)
	{
		cnt++;
		root = root->right;
	}
	return cnt;
}
int countNodes(Node* root) 
{
	if(root == NULL)
		return 0;
	int lh = left_height(root);
	int rh = right_height(root);
	if(lh == rh) return (1<<lh) - 1;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
	
	return 0;
}

// Height of Full Binary Tree -> 2^height - 1
// Time Complexity - O(LogN)
// Space Complexity - O(LogN)