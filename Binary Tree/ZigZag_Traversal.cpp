#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};
    vector<vector<int>> ans;
    int flag = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int sz = q.size();
        vector<int> temp;
        while (sz--)
        {
            TreeNode *r = q.front();
            q.pop();
            temp.push_back(r->val);
            if (r->left)
                q.push(r->left);
            if (r->right)
                q.push(r->right);
        }
        if (flag == 0)
            ans.push_back(temp);
        else
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        flag = 1 - flag;
    }
    return ans;
}

int main()
{

    return 0;
}