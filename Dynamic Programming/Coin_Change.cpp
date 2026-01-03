#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*amount)
// Space Complexity: O(n*amount)
int solve(int i, int amt, vector<int> &coins, vector<vector<int>> &dp)
{
    if (amt == 0)
        return 0;
    if (i == 0)
    {
        if (amt % coins[0] == 0)
            return amt / coins[0];
        return 1e8;
    }
    if (dp[i][amt] != -1)
        return dp[i][amt];
    int nottake = solve(i - 1, amt, coins, dp);
    int take = 1e8;
    if (coins[i] <= amt)
        take = 1 + solve(i, amt - coins[i], coins, dp);
    return dp[i][amt] = min(take, nottake);
}

// Time Complexity: O(n*amount)
// Space Complexity: O(n*amount) -> No Recursion Stack
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    // int ans = solve(n-1,amount,coins,dp);
    // return ans>=1e8 ? -1 : ans;

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e8;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int nottake = dp[i - 1][j];
            int take = 1e8;
            if (coins[i] <= j)
                take = 1 + dp[i][j - coins[i]];
            dp[i][j] = min(take, nottake);
        }
    }
    return dp[n - 1][amount] == 1e8 ? -1 : dp[n - 1][amount];
}

int main()
{

    return 0;
}