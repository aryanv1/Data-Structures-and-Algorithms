#include <bits/stdc++.h>
using namespace std;
#define ll long long int

pair<int,pair<int,int>> solve(Node *root) // {size,{minimum,maximum}}
{
	if(root == NULL)
		return {0,INT_MAX,INT_MIN};
	pair<int,pair<int,int>> left = solve(root->left);
	pair<int,pair<int,int>> right = solve(root->right);
	int size = left.first + right.first;
	if(root->val > left.second.second && root->val < right.second.first)
	{
		return {1+size,{min(root->val,left.second.first),
				max(root->val,right.second.second)}};
	}
	else
	{
		return {max(left.first,right.first),{INT_MIN,INT_MAX}};
	}
}

void largestBST(Node *root)
{	
	return solve(root).first;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(N) // recursion stack space
// Pair of pair will have size, min and max -> for left pairs, we will see that the current node's value is greater than left's maximum and for right we will see that current node value is less than minimum.
// Then update the pairs and return accordingly
// if condition is false then return max of left and right size
// If it is true then pass size+1.