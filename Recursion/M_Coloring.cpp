#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time - O(v^m)
bool solve(int node, vector<int> adj[], int n, int m, vector<int> &ans)
{
	if(node == n)
		return true;
	int col[m+1] = {0};
	for(auto it : adj[node])
	{
		col[ans[it]] = 1; // Marking colors of neighbouring nodes
	}
	for(int i=1; i<=m; i++)
	{
		if(!col[i])
		{
			ans[node] = i;
			if(solve(node+1,adj,n,m,ans) == true)
				return true;
			ans[node] = 0;
		}
	}
	return false;
}
bool graphColoring(bool graph[101][101], int m, int n) 
{
	vector<int> adj[n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(graph[i][j] == 1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	vector<int> ans(n,0);
	return solve(0,adj,n,m,ans);
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N^M)
// Space Complexity - O(N)