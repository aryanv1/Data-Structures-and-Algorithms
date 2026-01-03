#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

int solve(int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = solve(i - 1, j, dp);
    int left = solve(i, j - 1, dp);

    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = i > 0 ? dp[i - 1][j] : 0;
                int left = j > 0 ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// If given Unique paths with obstacles
// Then just add an extra check for obstacles
// i.e, if(obstacleGrid[i][j] == 1) dp[i][j] = 0;

int main()
{

    return 0;
}