#include <bits/stdc++.h>
using namespace std;
#define ll long long int

TreeNode *first;
TreeNode *last;
TreeNode *prev;
void inorder(TreeNode *node)
{
	if(node == NULL)
		return ;

	inorder(node->left);
	// finding the culprit element
	if(node->val < prev->val)
	{
		if(first == NULL)
		{
			first = prev;
			last = node;
		}
		else
			last = node;
		// for second culprit element we only require the element itself instead of its previous element
	}
	prev = node;
	inorder(node->right);
}
void recoverTree(TreeNode* root) {
	prev = new TreeNode(INT_MIN);
	inorder(root);
	if(first && last)
		swap(first->val,last->val);
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(1)