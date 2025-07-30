#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int start,vector<int> adj[],vector<int> &ls,int vis[])
{
    vis[start] = 1;
    ls.push_back(start);
    for(auto it : adj[start])
    {
        if(!vis[it])
        dfs(it,adj,ls,vis);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) 
{
    // Code here
    vector<int> ls;
    int start = 0;
    int vis[V] = {0};
    dfs(start,adj,ls,vis);
    return ls;
}

int main()
{
	int v,e;
	cin>>v>>e;
	vector<int> adj[v];
	for(int i=0; i<v; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> dfs = dfsOfGraph(v,adj);
	for(int i=0; i<dfs.size(); i++)
		cout<<dfs[i]<<" ";
	cout<<endl;
	return 0;
}
//Time Complexity - O(V) + O(2E) (undirected graph)
//for directed it will depend on number of edges	
//Space Complexity - O(V) recursion stack space