#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> topView(Node *root)
{
    // Create a vector to store the final answer
    vector<int> ans;
    // If the tree is empty, return an empty result
    if (root == NULL)
    {
        return ans;
    }
    // Create a map to store vertical level -> node value (only first encountered)
    map<int, int> mpp;
    // Create a queue for BFS that stores {node, vertical_level}
    queue<pair<Node *, int>> q;
    // Push the root node with vertical level 0
    q.push({root, 0});
    // Start BFS traversal
    while (!q.empty())
    {
        // Extract the front element of the queue
        auto it = q.front();
        q.pop();
        // Get the node and its vertical position
        Node *node = it.first;
        int line = it.second;

        // If this vertical position is being visited for the first time, store it
        if (mpp.find(line) == mpp.end())
        {
            mpp[line] = node->data;
        }

        // If there is a left child, push it with vertical level - 1
        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }
        // If there is a right child, push it with vertical level + 1
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }
    // Traverse the map and store values in the answer vector
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    // Return the result
    return ans;
}

vector<int> bottomView(Node *root)
{
    // Vector to store the result
    vector<int> ans;

    // Check if the tree is empty
    if (root == NULL)
    {
        return ans;
    }
    // Map to store the bottom view nodes
    // based on their vertical positions
    map<int, int> mpp;
    // Queue for BFS traversal, each
    // element is a pair containing node
    // and its vertical position
    queue<pair<Node *, int>> q;
    // Push the root node with its vertical
    // position (0) into the queue
    q.push({root, 0});
    // BFS traversal
    while (!q.empty())
    {
        // Retrieve the node and its vertical
        // position from the front of the queue
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;

        // Update the map with the node's data
        // for the current vertical position
        mpp[line] = node->data;

        // Process left child
        if (node->left != NULL)
        {
            // Push the left child with a decreased
            // vertical position into the queue
            q.push({node->left, line - 1});
        }
        // Process right child
        if (node->right != NULL)
        {
            // Push the right child with an increased
            // vertical position into the queue
            q.push({node->right, line + 1});
        }
    }
    // Transfer values from the
    // map to the result vector
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

// Left/Right View Brute Force Approach
vector<vector<int>> levelOrder(Node *root)
{
    // Initialize the final 2D vector
    vector<vector<int>> ans;
    // If the tree is empty, return empty vector
    if (!root)
        return ans;
    // Create a queue to hold tree nodes
    queue<Node *> q;
    // Start with the root node
    q.push(root);
    // Loop until queue is empty
    while (!q.empty())
    {
        // Get the number of nodes at the current level
        int size = q.size();
        // Vector to store current level nodes
        vector<int> level;
        // Process all nodes at the current level
        for (int i = 0; i < size; i++)
        {
            // Get the front node from the queue
            Node *node = q.front();
            q.pop();
            // Add its data to the level vector
            level.push_back(node->data);
            // Enqueue left child if exists
            if (node->left)
                q.push(node->left);
            // Enqueue right child if exists
            if (node->right)
                q.push(node->right);
        }
        // Add current level to the answer
        ans.push_back(level);
    }
    return ans;
}

// Function to return the left view
vector<int> leftView(Node *root)
{
    // Get the level order traversal
    vector<vector<int>> levels = levelOrder(root);
    // Vector to store left view
    vector<int> left;
    // Pick first element of each level
    for (auto &level : levels)
    {
        left.push_back(level[0]);
    }
    return left;
}

// Function to return the right view
vector<int> rightView(Node *root)
{
    // Get the level order traversal
    vector<vector<int>> levels = levelOrder(root);
    // Vector to store right view
    vector<int> right;
    // Pick last element of each level
    for (auto &level : levels)
    {
        right.push_back(level.back());
    }
    return right;
}

// Left/Right View Optimal Approach
void leftDFS(Node *node, int level, vector<int> &res)
{
    // Base case: null node
    if (!node)
        return;
    // If this is the first node at the current level
    if (res.size() == level)
        res.push_back(node->data);
    // Explore left subtree first
    leftDFS(node->left, level + 1, res);
    // Then explore right subtree
    leftDFS(node->right, level + 1, res);
}

// Recursive function to get right view
void rightDFS(Node *node, int level, vector<int> &res)
{
    if (!node)
        return;
    if (res.size() == level)
        res.push_back(node->data);
    // Explore right subtree first
    rightDFS(node->right, level + 1, res);
    // Then explore left subtree
    rightDFS(node->left, level + 1, res);
}

vector<int> leftViewOptimal(Node *root)
{
    vector<int> res;
    leftDFS(root, 0, res);
    return res;
}

vector<int> rightViewOptimal(Node *root)
{
    vector<int> res;
    rightDFS(root, 0, res);
    return res;
}

int main()
{
    cout << "Hello World" << endl;
    return 0;
}