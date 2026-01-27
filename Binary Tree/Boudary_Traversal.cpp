#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Take left boundary excluding leaf nodes
// If there is no left child, go to right child
// Similarly for right boundary
void left_boundary(Node *root, vector<int> &ans)
{
    Node *p = root;
    while (p)
    {
        if (p->left || p->right)
            ans.push_back(p->data);
        if (p->left)
            p = p->left;
        else
            p = p->right;
    }
}
// Inorder traversal to get leaf nodes
// Because leaf nodes are present in inorder fashion. 
void leaf_boundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    leaf_boundary(root->left, ans);
    if (!root->left && !root->right)
        ans.push_back(root->data);
    leaf_boundary(root->right, ans);
}
void right_boundary(Node *root, vector<int> &ans)
{
    Node *p = root;
    stack<int> st;
    while (p)
    {
        if (p->left || p->right)
            st.push(p->data);
        if (p->right)
            p = p->right;
        else
            p = p->left;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> ans;
    if (!root->left && !root->right)
        return {root->data};
    ans.push_back(root->data);
    if (root->left)
        left_boundary(root->left, ans);
    leaf_boundary(root, ans);
    if (root->right)
        right_boundary(root->right, ans);
    return ans;
}

int main()
{

    return 0;
}