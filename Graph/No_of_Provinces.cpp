#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(vector<vector<int>>&adj,int u,vector<int>&vis)
 {
    vis[u]=true;
    for(int v=0;v<adj.size();v++)
    {
        if(!vis[v] && adj[u][v]==1)
        {
            dfs(adj,v,vis);
        }
    }
}
int numProvinces(vector<vector<int>> adj, int v) 
{
    vector<int>vis(v,0);
    int count=0;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(adj,i,vis);
            count++;
        }
    }
    return count;
}

int main()
{
	int v;
	cin>>v;
	vector<vector<int>> adj;
	for(int i=0; i<v; i++)
	{
		vector<int> temp;
		for(int j=0; j<v; j++)
		{
			int m;
			cin>>m;
			temp.push_back(m);
		}
		adj.push_back(temp);
	}
	int k = numProvinces(adj,v);
	cout<<k<<endl;
	return 0;
}
/*Input
3
1 0 1
0 1 0
1 0 1
*/