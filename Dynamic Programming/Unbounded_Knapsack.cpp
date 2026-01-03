#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*W)
// Space Complexity: O(n*W)
int solve(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return (W / wt[0]) * val[0];
    }
    if (dp[i][W] != -1)
        return dp[i][W];

    int notpick = solve(i - 1, W, val, wt, dp);
    int pick = 0;
    if (wt[i] <= W)
        pick = val[i] + solve(i, W - wt[i], val, wt, dp);
    return max(pick, notpick);
}

// Time Complexity: O(n*W)
// Space Complexity: O(n*W) -> No Recursion Stack
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    // return solve(n-1, capacity, val, wt,dp);
    for (int i = 0; i <= capacity; i++)
        dp[0][i] = (i / wt[0]) * val[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (wt[i] <= j)
                pick = val[i] + dp[i][j - wt[i]];
            dp[i][j] = max(pick, notpick);
        }
    }
    return dp[n - 1][capacity];
}

int main()
{

    return 0;
}