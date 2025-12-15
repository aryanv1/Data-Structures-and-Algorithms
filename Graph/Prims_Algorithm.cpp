#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int spanningTree(int V, vector<vector<int>> adj[])
{
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	vector<int> vis(V, 0);
	int sum = 0;
	// weight,node,parent
	pq.push({0, 0, -1});
	// data structure to store node pairs
	vector<pair<int, int>> ans;
	while (!pq.empty())
	{
		auto it = pq.top();
		pq.pop();
		int node = it[1];
		int wt = it[0];
		int par = it[2];

		if (vis[node] == 1)
			continue;
		vis[node] = 1;
		sum += wt;
		if (par != -1)
			ans.push_back({node, par});
		for (auto it : adj[node])
		{
			int adjnode = it[0];
			int adjwt = it[1];
			if (vis[adjnode] == 0)
			{
				pq.push({adjwt, adjnode, node});
			}
		}
	}
	return sum;
}

int main()
{
	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges)
	{
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}
	int sum = spanningTree(V, adj);
	cout << sum << endl;
	return 0;
}

// Time Complexity - O(E*logE)
// Space Complexity - O(V+E)

// Minimum Spanning Tree - N nodes and N-1 edges such that we can reach to every node from every node
// Applies on Acyclic UDG
// Intuition - greedy approach -> take the node with min weight first