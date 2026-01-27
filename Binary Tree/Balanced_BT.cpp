#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree
// Check if a binary tree is balanced or not
int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = solve(root->left);
    if (lh == -1)
        return -1;
    int rh = solve(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
bool isBalanced(TreeNode *root)
{
    int k = solve(root);
    if (k == -1)
        return 0;
    return 1;
}

int main()
{

    return 0;
}