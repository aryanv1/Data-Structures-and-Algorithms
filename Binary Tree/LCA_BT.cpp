#include <bits/stdc++.h>
using namespace std;
#define ll long long int

Node* LCA(Node *root, int a, int b)
{
	if(root == NULL)
		return NULL;

	Node *left = LCA(root->left,a,b);
	Node *right = LCA(root->right,a,b);

	if((left && right) || (root->val == a) || (root->val == b))
		return root;

	return (left == NULL) ? right : left;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(N)