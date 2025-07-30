#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int spanningTree(int V, vector<vector<int>> adj[])
{
    // 1 - 2 wt = 5
    /// 1 - > (2, 5)
    // 2 -> (1, 5)

    // 5, 1, 2
    // 5, 2, 1
    // V+E
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			int adjNode = it[0];
			int wt = it[1];
			int node = i;

			edges.push_back({wt, {node, adjNode}});
		}
	}
	DisjointSet ds(V);
	// ELogE
	sort(edges.begin(), edges.end());
	int mstWt = 0;
	// E*4alpha*2
	for (auto it : edges) {
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;

		if (ds.findUPar(u) != ds.findUPar(v)) {
			mstWt += wt;
			ds.unionBySize(u, v);
		}
	}

	return mstWt;
}

int main()
{
	int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    int mstWt = spanningTree(V, adj);
    cout<<mstWt<<endl;
	return 0;
}

//Time Complexity - O(N+E) + O(E logE) + O(E*4α*2)
//Space Complexity - O(N)(parent) + O(N)(rank) + O(E)(edges)