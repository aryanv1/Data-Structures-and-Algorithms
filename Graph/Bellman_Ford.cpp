#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) 
{
    // Code here
    vector<int> dist(V,1e8);
    dist[S] = 0;
    for(int i=0; i<V-1; i++)
    {
        for(auto it : edges)
        {
            int from = it[0];
            int to = it[1];
            int dis = it[2];
            if(dist[from] != 1e8 && dist[from] + dis < dist[to])
            {
                dist[to] = dis + dist[from];
            }
        }
    }
    //Nth relaxation to check negative cycle;
    for(auto it : edges)
    {
        int from = it[0];
        int to = it[1];
        int dis = it[2];
        if(dist[from] != 1e8 && dist[from] + dis < dist[to])
        {
            return {-1};
        }
    }
    return dist;
}

int main()
{
	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	vector<int> ans = bellman_ford(V,edges,S);
	for (int i = 0; i < V; ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

// Time Complexity - O(V*E)
//SpaceComplexity - O(V)

// Only applied on DG -> represent UG in DG
// (N-1) relaxations

// Why (N-1) times ? -> because on each iteration an edge is getting relaxed, so on last iteration, last edges will be relaxed because in worst case you'll reach the last edges after (N-1) edges.

// Negative edge -> If on Nth iteration, any edge weight is still getting reduced then it will have negative edge cycle.