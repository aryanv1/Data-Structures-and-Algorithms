#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Using Set Data Structure   // times === edges  k === src
// If we got an dist which is less than what is there in dist array (not 1e9)
// then we remove the old pair from set and insert the new pair with updated distance
// This ensures that there is only one entry for each node in the set at any time
// In priority queue, we cannot remove the old entry, so multiple entries for same node can exist
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < times.size(); i++)
    {
        int u = times[i][0];
        int v = times[i][1];
        int wt = times[i][2];

        adj[u - 1].push_back({v - 1, wt});
    }
    set<pair<int, int>> s;
    vector<int> ans(n, 1e9);
    ans[k - 1] = 0;
    s.insert({0, k - 1});
    int maxi = -1;
    while (!s.empty())
    {
        pair<int, int> p = *s.begin();
        int dis = p.first;
        int node = p.second;
        s.erase(p);

        for (auto it : adj[node])
        {
            int neighbour = it.first;
            int adjweight = it.second;

            if (adjweight + dis < ans[neighbour])
            {
                if (ans[neighbour] != 1e9)
                    s.erase({ans[neighbour], neighbour});

                ans[neighbour] = dis + adjweight;
                s.insert({ans[neighbour], neighbour});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 1e9)
            return -1;
        maxi = max(maxi, ans[i]);
    }
    return maxi;
}

// Using Priority Queue
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans(V, 1e9);
    // vector<int> parent(V,-1);
    ans[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int neighbour = it[0];
            int edgewEIGHT = it[1];

            if ((edgewEIGHT + dis) < ans[neighbour])
            {
                ans[neighbour] = edgewEIGHT + dis;
                // parent[neighbour] = node;
                pq.push({ans[neighbour], neighbour});
            }
        }
    }
    return ans;
}

int main()
{
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

// Time Complexity - O(E*log(V))
// Space Complexity - O(V) + O(V) -> for dist array and priority queue

// In order to print the path of the shortest distance,
// we should store the parent of each node in one array.
// And After that, traverse back in that array i.e,
// from destination node and going to parent of each node and finally we
// reach to src node and we'll get our path. Here O(V) time complexity will be added to above.

// Don't work for negative edges weights because if edges weight between
// two nodes is let say -2 then every time on reaching a node and travelling
// to its adjacent nodes will reduce distance by that amount i.e, -2 then -4,-6 and so on....infinte loop