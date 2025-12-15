#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(V+E)
// Space Complexity - O(2V)
// Visted array for not reiterating nodes
// Path array for checking if node is in current path or not
bool dfs(int ind, vector<int> adj[], vector<int> &vis, vector<int> &path)
{
    vis[ind] = 1;
    path[ind] = 1;
    for (auto it : adj[ind])
    {
        // When Node is not visited
        if (!vis[it])
        {
            if (dfs(it, adj, vis, path) == true)
                return true;
        }
        // previously visited but not have the same path
        else if (path[it])
            return true;
    }
    path[ind] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> path(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, path) == true)
                return true;
        }
    }
    return false;
}

// Also done using Kahn's Algo - BFS:
// If No. of elements in topo array is less than N then there is cycle.
// Cycle will not allow indegree of some nodes to be zero.
// Which will cause the topo array to have less than N elements.

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bool ch = isCyclic(v, adj);
    cout << ch << endl;
    return 0;
}
/*
Input
10 20
7 2
2 3
3 1
1 6
6 9
9 8
8 5
5 4
4 0
8 4
6 8
7 0
1 5
9 1
5 1
1 9
7 1
8 7
1 8
2 7
*/