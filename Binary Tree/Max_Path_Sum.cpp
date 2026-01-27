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

int solve(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int l = max(0, solve(root->left, maxi));
    int r = max(0, solve(root->right, maxi));

    maxi = max(maxi, root->val + l + r);

    return root->val + max(l, r);
}
int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
}

int main()
{

    return 0;
}