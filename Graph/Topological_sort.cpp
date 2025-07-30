#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Kahn's Algorithm / BFS
vector<int> tSort(int V, vector<int> adj[])
{
	int indegree[V] = {0};
	queue<int> q;
	for(int i=0; i<V; i++)
	{
		for(auto it : adj[i])
		{
			indegree[it]++;
		}
	}
	for(int i=0; i<V; i++)
	{
		if(indegree[i] == 0)
			q.push(i);
	}
	vector<int> topo;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for(auto it : adj[node])
		{
			indegree[it]--;
			if(indegree[it] == 0)
				q.push(it);
		}
	}
	return topo;
}

// DFS Algorithm
void dfs_sort(int node,vector<int> adj[], vector<int>&vis, stack<int> &s)
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs_sort(it,adj,vis,s);
        }
    }
    s.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{ 
    vector<int> vis(V,0);
    stack<int> s;
    for(int i=0; i<V; i++)
    {
	   if(!vis[i])
	   {
	       dfs_sort(i,adj,vis,s);
	   }
    }
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

signed main()
{
	int v,e;
	cin>>v>>e;
	vector<int> adj[v];
	for(int i=0; i<e; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	vector<int> ans;
	ans = tSort(v,adj);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
/*Input
5 4
0 2
1 2
3 1
0 4
Time Complexity - O(V+E)
Space Complexity - O(V)
*/