#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*W)
// Space Complexity: O(n*W)
int solve(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (wt[i] <= W)
            return val[i];
        return 0;
    }

    if (dp[i][W] != -1)
        return dp[i][W];

    int notpick = solve(i - 1, W, val, wt, dp);
    int pick = 0;
    if (wt[i] <= W)
        pick = val[i] + solve(i - 1, W - wt[i], val, wt, dp);

    return dp[i][W] = max(pick, notpick);
}

// Time Complexity: O(n*W)
// Space Complexity: O(n*W) -> No Recursion Stack
// Can also be done in O(W) space by using 1D array and iterating W from high to low
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    // code here
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    // return solve(n-1, W, val, wt, dp);
    // For every wt gretaer then wt[0], we can pick that val
    // Since less weight cannot be taken
    for (int i = wt[0]; i <= W; i++)
        dp[0][i] = val[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (wt[i] <= j)
                pick = val[i] + dp[i - 1][j - wt[i]];
            dp[i][j] = max(pick, notpick);
        }
    }
    return dp[n - 1][W];
}

int main()
{

    return 0;
}