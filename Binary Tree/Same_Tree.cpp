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

// Same code for symmetric trees
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if ((!p && q) || (!q && p))
        return false;
    if (p->val != q->val)
        return false;
    if (isSameTree(p->left, q->left) == false)
        return false;
    if (isSameTree(p->right, q->right) == false)
        return false;
    return true;
}

int main()
{

    return 0;
}