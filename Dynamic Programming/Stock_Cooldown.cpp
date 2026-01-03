#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Just omit the cooldown day by moving to ind+2 after selling
// Memoization
// Time Complexity: O(N*2)
// Space Complexity: O(N*2) + O(N) for recursion stack
int getAns(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp)
{
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind >= n)
        return 0;

    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit;

    if (buy == 0)
    { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }

    if (buy == 1)
    { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 2, 0, n, dp));
    }

    // Store the result in the DP array and return
    return dp[ind][buy] = profit;
}

// Tabulation
// Time Complexity: O(N*2)
// Space Complexity: O(N*2)
int stockProfit(vector<int> &Arr)
{
    int n = Arr.size();
    // Create a 2D DP array with dimensions (n+2) x 2, initialized to 0
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit;

            if (buy == 0)
            { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1)
            { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 2][0]);
            }

            // Store the computed profit in the DP array
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

int main()
{

    return 0;
}