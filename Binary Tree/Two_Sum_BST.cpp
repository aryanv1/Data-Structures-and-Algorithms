#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class BSTIterator{
public:
	stack<TreeNode *> s;
	bool reverse = true;
    // reverse -> true -> before
    // reverse -> false -> left
	BSTIterator(TreeNode *node, bool isreverse)
	{
		reverse = isreverse;
		pushAll(node);
	}

	int next()
	{
		TreeNode *curr = s.top();
		s.pop();
		if(reverse)
		{
			if(curr->left)
				pushAll(curr->left);
		}
		else
		{
			if(curr->right)
				pushAll(curr->right);
		}
		return curr->val;
	}

	bool hasnext()
	{
		return !s.empty();
	}

private:
	void pushAll(TreeNode *node)
	{
		while(node)
		{
			s.push(node);
			if(reverse)
				node = node->right;
			else
				node = node->left;
		}
	}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		BSTIterator left(root,0);
		BSTIterator right(root,1);
		int i = left.next();
		int j = right.next();
		while(i < j)
		{
			if(i+j == k) return true;
			else if(i+j < k)
				i = left.next();
			else
				j = right.next();
		}
		return false;
	}
};

int main()
{
	
	return 0;
}