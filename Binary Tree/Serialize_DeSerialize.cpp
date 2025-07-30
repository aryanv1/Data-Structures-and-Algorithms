#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Here we have serialized based on preorder traversal
// In deserialization we'll simply again do preorder traversal
void solve1(TreeNode* root, string &ans)
{
	if(root == NULL)
	{
		ans += "N ";
		return ;
	}
	ans += to_string(root->val) + " ";
	solve1(root->left,ans);
	solve1(root->right,ans);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
	string ans = "";
	solve1(root,ans);
	return ans;
}

TreeNode* solve2(string &s, int &i)
{
	if(s[i] == 'N')
	{
		i = i+2;
		return NULL;
	}
	string k;
	while(s[i] != ' ')
		k += s[i++];
	i++;
	TreeNode *node = new TreeNode(stoi(k));
	node->left = solve2(s,i);
	node->right = solve2(s,i);
	return node;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
	if(data.size() == 0) return NULL;
	int i = 0;
	TreeNode *root = solve2(data,i);
	return root;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(N)