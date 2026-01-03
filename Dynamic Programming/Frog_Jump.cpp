#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
// If there are K jumps instead of 2 jumps, then just add a loop for K jumps
int minCost(vector<int> &height)
{
    int n = height.size();
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int a = (i - 2 >= 0 ? abs(height[i] - height[i - 2]) + dp[i - 2] : 1e9);
        dp[i] = min(abs(height[i] - height[i - 1]) + dp[i - 1], a);
    }
    return dp[n - 1];
}

// Optimized Space Complexity: O(1)
int minCost(vector<int> &height)
{
    int n = height.size();
    int prev2 = 0;
    int prev1 = 0;
    for (int i = 1; i < n; i++)
    {
        int a = (i - 2 >= 0 ? abs(height[i] - height[i - 2]) + prev2 : 1e9);
        int curr = min(abs(height[i] - height[i - 1]) + prev1, a);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{

    return 0;
}