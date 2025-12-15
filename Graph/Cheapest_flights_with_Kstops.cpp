#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(E+V)
// Space Complexity - O(N) + O(N) -> for adj list and dist array
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> ans(n, 1e9);
    vector<pair<int, int>> adj[n];
    for (int p = 0; p < flights.size(); p++)
    {
        int i = flights[p][0];
        int j = flights[p][1];
        int k = flights[p][2];
        adj[i].push_back({j, k});
    }
    queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {src, 0}});
    ans[src] = 0;
    while (!pq.empty())
    {
        auto it = pq.front();
        pq.pop();
        int el = it.second.first;
        int dis = it.second.second;
        int st = it.first;

        if (st > k)
            continue;
        for (auto i : adj[el])
        {
            int next = i.first;
            int d = i.second;
            if (st <= k && d + dis < ans[next])
            {
                ans[next] = d + dis;
                pq.push({1 + st, {next, d + dis}});
            }
        }
    }
    if (ans[dst] == 1e9)
        return -1;
    return ans[dst];
}

int main()
{
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int ans = findCheapestPrice(n, flights, src, dst, K);
    cout << ans << endl;
    return 0;
}

// Not use Priority Queue because it will always take minimum and which will miss the other routes
// and also it will give TLE due ElogV time complexity. Here it is (E+V)