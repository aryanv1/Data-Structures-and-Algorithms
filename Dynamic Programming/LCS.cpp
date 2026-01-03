#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
int solve(int i, int j, string &t1, string &t2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (t1[i] == t2[j])
        return dp[i][j] = 1 + solve(i - 1, j - 1, t1, t2, dp);
    else
        return dp[i][j] = max(solve(i - 1, j, t1, t2, dp), solve(i, j - 1, t1, t2, dp));
}

// Time Complexity: O(n*m)
// Space Complexity: O(n*m) -> No Recursion Stack
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return solve(n-1,m-1,text1,text2,dp);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
    /*
        ******** Print LCS ********
        int i=n, j=m;
        int ind = dp[n][m]-1;
        string ans(ind+1, ' '); // Initialize string of length dp[n][m]
        while(i>0 && j >0)
        {
            // Characters match, part of LCS move to diagonal
            if(text1[i-1] == text2[j-1])
            {
                ans[ind] = text1[i-1];
                ind--;
                i--;
                j--;
            }
            // Move in the direction of the larger value
            else if(dp[i-1][j] > dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    */
}

int main()
{

    return 0;
}