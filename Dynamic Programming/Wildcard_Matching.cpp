#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(N*M)
// Space Complexity: O(N*M)
bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        while (j >= 0)
        {
            if (p[j--] != '*')
                return false;
        }
        return true;
    }
    if (j < 0)
        return false;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == p[j] || p[j] == '?')
        return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
    else if (p[j] == '*')
    {
        // Empty
        bool a = solve(i, j - 1, s, p, dp);
        // sequence
        bool b = solve(i - 1, j, s, p, dp);
        return dp[i][j] = a | b;
    }
    else
        return false;
}
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    // return solve(n-1, m-1, s, p, dp);
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        dp[i][0] = false;
    for (int j = 1; j <= m; j++)
    {
        bool f = true;
        for (int k = 0; k < j; k++)
        {
            if (p[k] != '*')
            {
                f = false;
                break;
            }
        }
        dp[0][j] = f;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

int main()
{

    return 0;
}