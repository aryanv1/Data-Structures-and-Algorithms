#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// When for same col and row, we sort elements
vector<vector<int>> verticalTraversal(TreeNode* root) 
{
	queue<pair<pair<int,int>,TreeNode*>> q;
    q.push({{0,0},root}); // {{c,r},node}
    multiset<pair<pair<int,int>,int>> s;
    while(!q.empty())
    {
    	pair<pair<int,int>,TreeNode*> p = q.front();
    	q.pop();
    	s.insert({{p.first.first,p.first.second},p.second->val});
    	if(p.second->left)
    	{
    		q.push({{p.first.first-1,p.first.second+1},p.second->left});
    	}
    	if(p.second->right)
    	{
    		q.push({{p.first.first+1,p.first.second+1},p.second->right});
    	}
    }
    vector<vector<int>> ans;
    auto i = s.begin();
    auto it = s.begin();
    vector<int> temp;
    while(it != s.end())
    {
    	if(it->first.first == i->first.first)
    	{
    		temp.push_back(it->second);
    		it++;
    	}
    	else
    	{
    		i = it;
    		ans.push_back(temp);
    		temp.clear();
    	}
    }
    ans.push_back(temp);
    return ans;
}

// When for same col and row, we insert according to level order
// Keeping first the element at smaller level
vector<int> verticalOrder(Node *root)
{
	map<int,vector<int>>m;

	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty())
	{
		Node *temp=q.front().first;
		int level=q.front().second;
		q.pop();

		m[level].push_back(temp->data);
		if(temp->left)
			q.push({temp->left,level-1});
		if(temp->right)
			q.push({temp->right,level+1});
	}


	vector<int>ans;
	for(auto x:m)
	{
		for(auto y:x.second)
		{
			ans.push_back(y);
		}
	}

	return ans;
}

int main()
{

	return 0;
}