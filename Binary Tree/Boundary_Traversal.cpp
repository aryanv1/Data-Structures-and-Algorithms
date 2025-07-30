#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void left_boundary(Node *root, vector<int> &ans)
{
	Node *p = root;
	while(p)
	{
		if(p->left || p->right)
			ans.push_back(p->data);

		if(p->left)
			p = p->left;
		else
			p = p->right;
	}
}

void leaf_boundary(Node *root, vector<int> &ans)
{
	if(root == NULL) 
		return ;

    //inorder traversal
	leaf_boundary(root->left,ans); 

	if(!root->left && !root->right)
		ans.push_back(root->data);

	leaf_boundary(root->right,ans);
}

void right_boundary(Node *root, vector<int> &ans)
{
	Node *p = root;
	stack<int> s;
	while(p)
	{
		if(p->left || p->right)
			s.push(p->data);

		if(p->right)
			p = p->right;
		else
			p = p->left;
	}
	while(!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}
}

vector<int> boundary(Node *root)
{
	vector<int> ans;
	if(!root->left && !root->right) return {root->data};
	ans.push_back(root->data);
	if(root->left)
		left_boundary(root->left,ans);

	leaf_boundary(root,ans);

	if(root->right)
		right_boundary(root->right,ans);
	return ans;
}

int main()
{
	
	return 0;
}