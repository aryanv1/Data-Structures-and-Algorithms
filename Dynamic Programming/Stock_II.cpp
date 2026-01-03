#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Here transaction fee can be added for each transaction
// So just subtract this fee while selling stock
// This can be one og the variations of stock problems

// Time Complexity: O(N*2)
// Space Complexity: O(N*2)
int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (ind == prices.size())
    {
        return 0;
    }
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int a = solve(ind + 1, buy, prices, dp);
    int b = 0;
    if (buy) // already bought one and now need to sell
        b = prices[ind] + solve(ind + 1, 0, prices, dp);
    else
        b = -prices[ind] + solve(ind + 1, 1, prices, dp);
    return dp[ind][buy] = max(a, b);
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -0));
    // return solve(0,0,prices,dp);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            int a = dp[i + 1][buy];
            int b = 0;
            if (buy)
                b = prices[i] + dp[i + 1][0];
            else
                b = -prices[i] + dp[i + 1][1];
            dp[i][buy] = max(a, b);
        }
    }
    return dp[0][0];
}
// Space Optimization
// Time Complexity: O(N*2)
// Space Complexity: O(1)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<int>> dp(n+1, vector<int>(2,-0));
    // return solve(0,0,prices,dp);
    vector<int> ahead(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> curr(2, 0);
        for (int buy = 1; buy >= 0; buy--)
        {
            int a = ahead[buy];
            int b = 0;
            if (buy)
                b = prices[i] + ahead[0];
            else
                b = -prices[i] + ahead[1];
            curr[buy] = max(a, b);
        }
        ahead = curr;
    }
    return ahead[0];
}

int main()
{

    return 0;
}