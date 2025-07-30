#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int Solve(int n, vector<vector<int>>& edge) 
{
	Disjoint_Set ds(n);
	int extra = 0;
	for(auto it : edge)
	{
		int u = it[0];
		int v = it[1];
		if(ds.findUPar(u) == ds.findUPar(v))
			extra++;
		else
		{
			ds.UnionBySize(u,v);
		}
	}
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		if(ds.parent[i] == i) cnt++;
	}
	if(extra < cnt-1) return -1;
	return cnt-1;
}

int main()
{
	int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    int ans = Solve(V, edge);
    cout<<ans<<endl;
	return 0;
}