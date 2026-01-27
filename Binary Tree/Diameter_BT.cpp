#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans = 0;
int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    ans = max(ans, left + right);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    solve(root);
    return ans;
}

int main()
{

    return 0;
}