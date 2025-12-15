#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Kosaraju's Algorithm
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
	vis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			dfs(it, adj, vis, st);
		}
	}
	st.push(node);
}
void dfs2(int node, vector<vector<int>> &adjR, vector<int> &vis)
{
	vis[node] = 1;
	for (auto it : adjR[node])
	{
		if (!vis[it])
		{
			dfs2(it, adjR, vis);
		}
	}
}
int kosaraju(int n, vector<vector<int>> &adj)
{
	stack<int> st;
	vector<int> vis(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			dfs(i, adj, vis, st);
		}
	}

	vector<vector<int>> adjR(n);
	for (int i = 0; i < n; i++)
	{
		vis[i] = 0;
		for (auto it : adj[i])
		{
			adjR[it].push_back(i);
		}
	}

	int scc = 0;
	while (!st.empty())
	{
		int node = st.top();
		st.pop();
		if (!vis[node])
		{
			scc++;
			dfs2(node, adjR, vis);
		}
	}

	return scc;
}

int main()
{

	return 0;
}

// Time Complexity - O(V+E)
// Space Complexity - O(V+E)
// Only valid for Directerd Graphs

// Steps:
// 1. Do a DFS traversal and push the nodes in stack after completing their DFS
// 2. Reverse the graph
// 3. Pop nodes from stack and do DFS on reversed graph if not visited
// 4. Count the number of DFS calls made in step 3 as that will be SCCs

// Why we are using stack?
// Because we need to process nodes in order of their finishing times
// Nodes which finish last should be processed first in reversed graph
// This ensures that we are always starting DFS from the "topmost" node of a SCC
// Our grah will be like SCC1 -> SCC2 -> SCC3
// So if we donot follow this order, we might start DFS from a node in SCC2 or SCC3
// and thus we will not able to correctly count all SCCs
// It can happen that we start DFS from a node in SCC2, and all nodes of SCC2 and SCC3
// get visited in that single DFS call, thus we count SCC2 and SCC3 as single SCC
// To avoid this, we use stack to store nodes based on finishing times