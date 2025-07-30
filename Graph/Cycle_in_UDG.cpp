#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool detect_dfs(int src,int parent, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    for(auto it : adj[src])
    {
        if(!vis[it])
        {
            if(detect_dfs(it,src,adj,vis) == true) return true;
        }
        else if(parent != it)
        {
            return true;
        }
    }
    return false;
}

bool detect_bfs(int src,vector<int> adj[], int vis[])
{
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push({it,node});
            }
            else if(parent != it)
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    int vis[V] = {0};
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            if(detect_dfs(i,-1,adj,vis)) return true;
        }
    }
    return false;
}

int main()
{
	int v,e;
	cin>>v>>e;
	vector<int> adj[v];
	for(int i=0; i<e; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool check = isCycle(v,adj);
	cout<<check<<endl;
	return 0;
}
//Time and space Complexity is same as in BFS
/*Input
5 5
0 1
1 0
1 4
1 2
2 1
2 3
3 2
3 4
4 1
4 3
*/