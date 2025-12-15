#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(N*N*log(N*N)) -> for each cell we are doing log(N*N) operations
// Space Complexity - O(N*N) for vis array and O(N*N) for priority queue
int swimInWater(vector<vector<int>> &grid)
{
	int n = grid.size();
	using T = pair<int, pair<int, int>>;
	vector<vector<int>> vis(n, vector<int>(n, 0));
	priority_queue<T, vector<T>, greater<T>> pq;
	pq.push({grid[0][0], {0, 0}});
	vis[0][0] = 1;
	int dr[4] = {-1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};
	while (!pq.empty())
	{
		int t = pq.top().first;
		int i = pq.top().second.first;
		int j = pq.top().second.second;
		pq.pop();
		if (i == n - 1 && j == n - 1)
			return max(t, grid[n - 1][n - 1]);
		for (int k = 0; k < 4; k++)
		{
			int r = i + dr[k];
			int c = j + dc[k];
			if (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c])
			{
				vis[r][c] = 1;
				pq.push({max(t, grid[r][c]), {r, c}});
			}
		}
	}
	return -1;
}

int main()
{

	return 0;
}