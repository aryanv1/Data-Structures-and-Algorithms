#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void flatten3(TreeNode* root) // based on Morris Traversal
{
	//Time - O(N), Space - O(1)
	if(!root) return ;
	TreeNode *curr = root;
	while(curr != NULL)
	{
		if(curr->left != NULL)
		{
			TreeNode *prev;
			prev = curr->left;
			while(prev->right)
				prev = prev->right;
			prev->right = curr->right;
			curr->right = curr->left;
			curr->left = NULL;
		}
		curr = curr->right;
	}
}

void flatten2(TreeNode* root) // insert right first to get preorder
{
	//Time - O(N), Space - O(N)
	stack<Node *> st;
	st.push(root);
	while(!st.empty());
	{
		Node *curr = st.top();
		st.pop();
		if(curr->right)
			st.push(curr->right);
		if(curr->left)
			st.push(curr->left);
		if(!st.empty())
			curr->right = st.top();
		curr->left =  NULL;
	}
}

TreeNode *prev = NULL;
void flatten1(TreeNode* root) // Reverse Postorder traversal
{
	//Time - O(N), Space - O(N)
	if(root == NULL)
		return ;
	flatten1(root->right);
	flatten1(root->left);

	root->right = prev;
	root->left = NULL;
	prev = root;
}

int main()
{
	
	return 0;
}