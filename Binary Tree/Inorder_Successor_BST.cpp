#include <bits/stdc++.h>
using namespace std;
#define ll long long int

Node * inOrderSuccessor(Node *root, Node *x)
{
	Node *successor = NULL;
	while(root)
	{
		if(x->data >= root->data)
			root = root->right;
		else // since root will be greater than x, so can be successor
		{
			successor = root;
			root = root->left;
		}
	}
	return successor;
}

int main()
{
	
	return 0;
}

// for predecessor, pre = root will come in if part and equals to condition will be with else