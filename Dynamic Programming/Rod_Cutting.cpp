#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*n)
// Space Complexity: O(n*n)
int solve(int i, int n, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return n * prices[i];
    }
    if (dp[i][n] != -1)
        return dp[i][n];
    int nottake = solve(i - 1, n, prices, dp);
    int take = 0;
    if (i + 1 <= n)
        take = prices[i] + solve(i, n - i - 1, prices, dp);

    return dp[i][n] = max(take, nottake);
}

// Time Complexity: O(n*n)
// Space Complexity: O(n*n) -> No Recursion Stack
int cutRod(vector<int> &price)
{
    // code here
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return solve(n-1,n,price,dp);
    for (int i = 0; i <= n; i++)
        dp[0][i] = i * price[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int nottake = dp[i - 1][j];
            int take = 0;
            if (i + 1 <= j)
                take = price[i] + dp[i][j - i - 1];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][n];
}

int main()
{

    return 0;
}