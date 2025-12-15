#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(V+2E)
// Space Complexity - O(V)
bool isBipartite(vector<vector<int>> &adj)
{
	int n = adj.size();
	vector<int> col(n, -1);
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (col[i] == -1)
		{
			q.push(i);
			col[i] = 0;
			while (!q.empty())
			{
				int node = q.front();
				q.pop();
				for (auto it : adj[node])
				{
					if (col[it] == col[node])
						return false;
					else if (col[it] == -1)
					{
						col[it] = 1 - col[node];
						q.push(it);
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	int V, E;
	V = 4, E = 8;
	// adjacency list for storing graph
	vector<vector<int>> adj(V);
	adj[0] = {1, 3};
	adj[1] = {0, 2};
	adj[2] = {1, 3};
	adj[3] = {0, 2};

	bool ans = isBipartite(adj);
	// returns 1 if bipartite graph is possible
	if (ans)
		cout << "Yes\n";
	// returns 0 if bipartite graph is not possible
	else
		cout << "No\n";

	return 0;
}
// Time Complexity - O(V+E)
// Space Complexity - O(V)