#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return INT_MAX - 200;
    if (i == 0 && j == 0)
        return grid[0][0];
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + solve(i - 1, j, grid, dp);
    int left = grid[i][j] + solve(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // return solve(n-1,m-1,grid);
    vector<vector<int>> dp(n, vector<int>(m, 1e9));
    // Tabulation
    // Time Complexity: O(n*m)
    // Space Complexity: O(n*m) -> No recursion stack space
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = grid[0][0];
            else
            {
                int up = i - 1 >= 0 ? dp[i - 1][j] : 1e9;
                int left = j - 1 >= 0 ? dp[i][j - 1] : 1e9;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{

    return 0;
}