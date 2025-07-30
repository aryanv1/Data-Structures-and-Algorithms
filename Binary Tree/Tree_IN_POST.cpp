#include <bits/stdc++.h>
using namespace std;
#define ll long long int

Node* create(int inorder[], int postorder[], int is, int ie, int ps, int pe) 
{
	if (ps > pe) 
	{
		return nullptr;
	}
	Node* node = new Node(postorder[pe]);

	int pos;
	for (int i = is; i <= ie; i++) 
	{
		if (inorder[i] == node->data) 
		{
			pos = i;
			break;
		}
	}
	int numslen = pos-is;
	// 											     lt      rt   r
	// Inorder -> 40 20 50 10 60 30  Postorder -> 40 50 20 60 30 10
 	// 		            -- -> Root                -------- ----- -- 
	node->left =
	create(inorder, postorder, is, pos - 1, ps, ps + numslen-1);
	node->right =
	create(inorder, postorder, pos + 1, ie, ps + numslen, pe - 1);

	return node;
}
Node *buildTree(int inorder[], int postorder[], int n) 
{
	return create(inorder, postorder, 0, n - 1, 0, n - 1);
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(N)
// In pre, we have not taken indices of preorder because there the order of taking root through preorder is similar to our recursive traversal and thus we can simply increment the index of preorder. But here we have to take root by taking the last element of every subarray we create.