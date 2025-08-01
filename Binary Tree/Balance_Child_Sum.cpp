#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void changeTree(Node *root)
{
	if(root == NULL) return;
	int child = 0;
	if(root->left) child += root->left->data;
	if(root->right) child += root->right->data;

	if(child >= root->data) root->data = child;
	else
	{
		if(root->left) root->left->data = root->data;
		if(root->right) root->right->data = root->data;
	}

	changeTree(root->left);
	changeTree(root->right);

	int total = 0;
	if(root->left) total += root->left->data;
	if(root->right) total += root->right->data;
	if(root->left || root->right) 
		root->data = total;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(Height of Tree)