#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// First Node in preorder is root
// find root in inorder and divide its left part as left subtree and right as right subtree
Node* createTree(int preorder[], int inorder[], int start, int end) 
{
	if (start > end) 
	{
		return NULL;
	}

	Node* node = new Node(preorder[preInd++]);

	int pos;
	for (int i = start; i <= end; i++) 
	{
		if (inorder[i] == node->data) 
		{
			pos = i;
			break;
		}
	}

	node->left = createTree(preorder, inorder, start, pos - 1);
	node->right = createTree(preorder, inorder, pos + 1, end);

	return node;
}
Node* buildTree(int inorder[],int preorder[], int n)
{
	return createTree(preorder, inorder, 0, n - 1);
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(N)