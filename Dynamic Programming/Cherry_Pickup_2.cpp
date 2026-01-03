#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*m*9)
// Space Complexity: O(n*m*m)
int solve(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int n, int m)
{
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
        return INT_MIN;
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int ans = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            int newJ1 = j1 + x;
            int newJ2 = j2 + y;
            if (j1 == j2)
                ans = max(ans, grid[i][j1] + solve(i + 1, newJ1, newJ2, grid, dp, n, m));
            else
                ans = max(ans, grid[i][j1] + grid[i][j2] + solve(i + 1, newJ1, newJ2, grid, dp, n, m));
        }
    }
    return dp[i][j1][j2] = ans;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve(0, 0, m - 1, grid, dp, n, m);
}

int main()
{

    return 0;
}