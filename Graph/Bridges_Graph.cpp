#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int timer = 1;
void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &low, vector<int> &tin, vector<vector<int>> &bridges)
{
	vis[node] = 1;
	tin[node] = low[node] = timer;
	timer++;
	for (auto it : adj[node])
	{
		if (it == parent)
			continue;
		if (!vis[it])
		{
			dfs(it, node, vis, adj, low, tin, bridges);
			low[node] = min(low[node], low[it]);
			// node -- it can be a bridge??
			if (tin[node] < low[it])
				bridges.push_back({node, it});
		}
		else
		{
			low[node] = min(low[node], low[it]);
		}
	}
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
	vector<int> adj[n];
	for (int i = 0; i < connections.size(); i++)
	{
		int u = connections[i][0];
		int v = connections[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<int>> bridges;
	vector<int> low(n);
	vector<int> tin(n);
	vector<int> vis(n, 0);
	dfs(0, -1, vis, adj, low, tin, bridges);
	return bridges;
}

int main()
{

	return 0;
}

// Time Complexity - O(V+E)
// Space Complexity - O(V+E+2V)

// Check for every adjacent nodes accept the parent
// and take the low of it if minimum than himself and
// if the low of adjacent is greater than the node's time,
// the definetly you cannot reach from anywhere else to that node,
// and thus that can be the bridge.