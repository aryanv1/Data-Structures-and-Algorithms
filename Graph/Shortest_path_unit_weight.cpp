#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src
{
	vector<int> ans(N,INT_MAX);
	ans[src] = 0;
	vector<vector<int>> v(N);
	for(int i=0; i<edges.size(); i++)
	{
            v[edges[i][0]].push_back(edges[i][1]);
	    //if graph is undirected
	    v[edges[i][1]].push_back(edges[i][0]);
	}
	queue<pair<int,int>> q;
	q.push({src,0});
	while(!q.empty())
	{
		int s = q.front().first;
		int d = q.front().second;
		q.pop();
		for(auto it : v[s])
		{
			if(d+1 < ans[it])
			{
				ans[it] = d+1;
				q.push({it,d+1});
			}
		}
	}
	for(int i=0; i<N; i++)
	{
		if(ans[i] == INT_MAX) ans[i] = -1;
	}
	return ans;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edges;
	for(int i=0; i<n; i++)
	{
		vector<int> temp;
		for(int j=0; j<2; j++)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		edges.push_back(temp);
	}
	vector<int> res = shortestPath(edges,n,m,0);
	for(auto x : res)
	{
		cout<<x<<" ";
	}
	return 0;
}
/*
9 10
0 1
0 3 
3 4 
4 5 
5 6 
1 2 
2 6 
6 7 
7 8 
6 8 
0
*/