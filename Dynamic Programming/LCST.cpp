#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Longest Common Substring
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Here we can do spce optimization as we only need previous row
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return solve(n-1,m-1,text1,text2,dp);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
            // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            // No carry forward as substring needs to be continuous
        }
    }
    return ans;
}

int main()
{

    return 0;
}