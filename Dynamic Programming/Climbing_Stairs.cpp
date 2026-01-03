#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int climbStairs(int n)
{
    vector<int> dp(n + 1, 1e9);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Optimized Space Complexity: O(1)
int climbStairs(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{

    return 0;
}