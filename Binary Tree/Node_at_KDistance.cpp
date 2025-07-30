#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
	queue<TreeNode*> q,q1;
	unordered_map<TreeNode*,TreeNode*> m;
	q1.push(root);
	while(!q1.empty())
	{
		TreeNode *node = q1.front();
		q1.pop();
		if(node->left)
		{
			q1.push(node->left);
			m[node->left] = node;
		}
		if(node->right)
		{
			q1.push(node->right);
			m[node->right] = node;
		}
	}

	q.push(target);
	set<TreeNode*> s;
	s.insert(target);
	int lev = 0;
	while(!q.empty())
	{
		int sz = q.size();
		if(lev == k) break;
		while(sz--)
		{
			TreeNode* p = q.front();
			q.pop();
			if(p->left && s.find(p->left) == s.end())
			{
				q.push(p->left);
				s.insert(p->left);
			}            
			if(p->right && s.find(p->right) == s.end())
			{
				q.push(p->right);
				s.insert(p->right);
			}  
			if(m.find(p) != m.end() && s.find(m[p]) == s.end())
			{
				q.push(m[p]);
				s.insert(m[p]);
			}
		}   
		lev++;       
	}
	vector<int> ans;
	while(!q.empty())
	{
		ans.push_back(q.front()->val);
		q.pop();
	}
	return ans;
}

int main()
{
	
	return 0;
}