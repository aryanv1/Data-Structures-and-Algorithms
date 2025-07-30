#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int mod = 1e9+7;
int countPaths(int n, vector<vector<int>>& roads) 
{
    // code here
    vector<pair<long long,long long>> adj[n];
    for(int i=0; i<roads.size(); i++)
    {
        adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
    }
    
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    vector<long long> ways(n,0);
    vector<long long> ans(n,LONG_MAX);
    ans[0] = 0;
    ways[0] = 1;
    pq.push({0,0});
    while(!pq.empty())
    {
        auto i = pq.top();
        pq.pop();
        long long node = i.second;
        long long t = i.first;
        for(auto it : adj[node])
        {
            long long next_node = it.first;
            long long tt = it.second;
            if(t+tt < ans[next_node])
            {
                ans[next_node] = t + tt;
                pq.push({ans[next_node],next_node});
                ways[next_node] = ways[node]%mod;
            }
            else if(t+tt == ans[next_node])
            ways[next_node] = (ways[next_node] + ways[node])%mod;
        }
    }
    return ways[n-1]%mod;
}

int main()
{
	int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    int ans = countPaths(n,edges);
    cout<<ans<<endl;
	return 0;
}