#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
	vis[node] = 1;
	for(auto it : adj[node])
	{
		if(!vis[it])
		{
			dfs(it,adj,vis,st);
		}
	}
	st.push(node);
}
void dfs2(int node, vector<vector<int>> &adjR, vector<int> &vis)
{
	vis[node] = 1;
	for(auto it : adjR[node])
	{
		if(!vis[it])
		{
			dfs2(it,adjR,vis);
		}
	}
}
int kosaraju(int n, vector<vector<int>>& adj)
{
	stack<int> st;
	vector<int> vis(n,0);
	for(int i=0; i<n; i++)
	{
		if(!vis[i])
		{
			dfs(i, adj, vis, st);
		}
	}

	vector<vector<int>> adjR(n);
	for(int i=0; i<n; i++)
	{
		vis[i] = 0;
		for(auto it : adj[i])
		{
			adjR[it].push_back(i);
		}
	}

	int scc = 0;
	while(!st.empty())
	{
		int node = st.top();
		st.pop();
		if(!vis[node])
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