#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorder(TreeNode *root)
{
	stack<TreeNode*> s;
	s.push(root);
	vector<int> ans;
	while(!s.empty())
	{
		TreeNode *n = s.top();
		s.pop();
		ans.push_back(n->val);
		// pushing right first because stack is LIFO so we get left on popping
		if(n->right)
			s.push(n->right);
		if(n->left)
			s.push(n->left);
	}
	return ans;
}

vector<int> Inorder(TreeNode *r)
{
	stack<TreeNode*> s;
	vector<int> ans;
	TreeNode* root = r;
	while(true)
	{
		if(root)
		{
			s.push(root);
			root = root->left;
		}
		else
		{
			if(s.empty()) break;
			root = s.top();
			s.pop();
			ans.push_back(root->val);
			root = root->right;
		}
	}
	return ans;
}

vector<int> postorder(TreeNode *root)
{
	stack<TreeNode*> s1,s2;
	s1.push(root);
	vector<int> ans;
	while(!s1.empty())
	{
		TreeNode* p = s1.top();
		s1.pop();
		s2.push(p);
		if(p->left)
			s1.push(p->left);
		if(p->right)
			s1.push(p->right);
	}
	while(!s2.empty())
	{
		ans.push_back(s2.top()->data);
		s2.pop();
	}
	return ans;
}

// Time Complexity - O(3N), Space Complexity - O(3N)
void AllThree(TreeNode *root)
{
	if(root == NULL)
		return ;
	vector<int> preorder,inorder,postorder;
	stack<pair<TreeNode*,int>> st; // {node,number}
	st.push({root,1});
	while(!q.empty())
	{
		auto it = q.front();
		q.pop();
		if(it.second == 1) // preorder -> left comes after data
		{
			preorder.push_back(it.first->data);
			it.second++;
			q.push(it);
			if(it.first->left)
				q.push({it.first->left,1});
		}
		else if(it.second == 2) // inorder -> left then data then right so pushed right
		{	
			inorder.push_back(it.first->data);
			it.second++;
			q.push(it);
			if(it.first->right)
				q.push({it.first->right,1});
		}
		else // last one is data so not pushed anything
		{
			postorder.push_back(it.first->data);
		}
	}
}

vector<int> Morris_Inorder(TreeNode *root)
{
	// Time - O(N) and Space - O(1)
	vector<int> Inorder;
	TreeNode *curr = root;
	while(curr != NULL)
	{
		if(curr->left == NULL)
		{
			Inorder.push_back(curr->val);
			curr = curr->right; 
		}
		else
		{
			TreeNode* temp = curr->left;
			while(temp->right && temp->right != curr) // rightmost guy of left subtree of current node
			{
				temp = temp->right;
			}
			if(temp->right == NULL)
			{
				temp->right = curr;
				// preorder.push_back(curr->val); for preorder
				curr = curr->left;
			}
			else
			{
				temp->right = NULL;
				Inorder.push_back(curr->val); // remove this in preorder
				curr = curr->right;
			}
		}
	}
	return Inorder;
}

int main()
{
	
	return 0;
}