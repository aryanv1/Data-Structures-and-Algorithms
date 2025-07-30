#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> printGraph(int V, vector<pair<int,int>>&edges) 
{
    vector<vector<int>> v(V);
    for(int i=0; i<edges.size(); i++)
    {
        v[edges[i].first].push_back(edges[i].second);
        //if graph is undirected
        v[edges[i].second].push_back(edges[i].first);
    }
    return v;
}

int main()
{
	int v,e;
	cin>>v>>e;
	vector<pair<int,int>> edges;
	for(int i=0; i<e; i++)
	{
		int u,v;
		cin>>u>>v;
		edges.push_back({u,v});
	}
	vector<vector<int>> ans = printGraph(v,edges);
	for(int i=0; i<ans.size(); i++)
	{
		for(int j=0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

//input
/*5 7
0 1
0 4
4 1
4 3
1 3
1 2
3 2
*/