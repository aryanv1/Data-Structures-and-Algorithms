#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    vector<int> bfs;
    queue<int> q;
    int vis[V] = {0};
    vis[0] = 1;
    q.push(0);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
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
	vector<int> ans = bfsOfGraph(v,adj);
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
//Space Complexity - O(V)
//Time Complexity - O(V) + O(2E)

//Input
/*
5 4
0 1
0 2
0 3
2 4
*/