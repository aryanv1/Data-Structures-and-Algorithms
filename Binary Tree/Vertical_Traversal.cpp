#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// When for same col and row, we sort elements
vector<vector<int>> verticalTraversal(TreeNode *root)
{
	queue<pair<TreeNode *, pair<int, int>>> q;
	// {vertical, level, node}
	map<int, map<int, multiset<int>>> mp;
	q.push({root, {0, 0}});
	while (!q.empty())
	{
		TreeNode *node = q.front().first;
		int i = q.front().second.first;	 // vertical
		int j = q.front().second.second; // level
		q.pop();

		mp[i][j].insert(node->val);

		if (node->left)
			q.push({node->left, {i - 1, j + 1}});
		if (node->right)
			q.push({node->right, {i + 1, j + 1}});
	}
	vector<vector<int>> ans;
	for (auto it : mp)
	{
		vector<int> temp;
		for (auto l : it.second)
			temp.insert(temp.end(), l.second.begin(), l.second.end());
		ans.push_back(temp);
	}
	return ans;
}

// When for same col and row, we insert according to level order
// Keeping first the element at smaller level
vector<int> verticalOrder(TreeNode *root)
{
	map<int, vector<int>> m;

	queue<pair<TreeNode *, int>> q;
	q.push({root, 0});
	while (!q.empty())
	{
		TreeNode *temp = q.front().first;
		int level = q.front().second;
		q.pop();

		m[level].push_back(temp->val);
		if (temp->left)
			q.push({temp->left, level - 1});
		if (temp->right)
			q.push({temp->right, level + 1});
	}

	vector<int> ans;
	for (auto x : m)
	{
		for (auto y : x.second)
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