#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)
int solve(int ind, vector<int> &coins, int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
    {
        if (sum % coins[0] == 0)
            return 1;
        return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    long long nottake = solve(ind - 1, coins, n, sum, dp);
    long long take = 0;
    if (coins[ind] <= sum)
        take = solve(ind, coins, n, sum - coins[ind], dp);
    return dp[ind][sum] = (take + nottake);
}

int change(int sum, vector<int> &coins)
{
    int N = coins.size();
    vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
    return solve(N - 1, coins, N, sum, dp);
}

int main()
{

    return 0;
}