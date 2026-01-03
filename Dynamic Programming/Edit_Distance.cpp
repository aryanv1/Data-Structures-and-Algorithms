#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(N*M)
// Space Complexity: O(N*M)
int solve(int i, int j, string &w1, string &w2, vector<vector<int>> &dp)
{
    if (j < 0)
        return i + 1;
    if (i < 0)
        return j + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (w1[i] == w2[j])
        return dp[i][j] = solve(i - 1, j - 1, w1, w2, dp);
    else
    {
        // Insert
        int a = 1 + solve(i, j - 1, w1, w2, dp);
        // Delete
        int b = 1 + solve(i - 1, j, w1, w2, dp);
        // Replace
        int c = 1 + solve(i - 1, j - 1, w1, w2, dp);
        return dp[i][j] = min(a, min(b, c));
    }
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return solve(n-1,m-1,word1,word2,dp);
    for (int i = 0; i <= n; i++)
        dp[i][0] = i; // not i+1 because we are already moving from 1 to n
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int a = 1 + dp[i - 1][j];
                int b = 1 + dp[i][j - 1];
                int c = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(a, min(b, c));
            }
        }
    }
    return dp[n][m];
}

// Space Optimized Approach
// Time Complexity: O(N*M)
// Space Complexity: O(M)
int editDistance(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();

    // Create two arrays to store previous and current row of edit distances
    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    // Initialize the first row
    for (int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }

    // Calculate edit distances row by row
    for (int i = 1; i <= n; i++)
    {
        cur[0] = i; // Initialize the first column of the current row
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                // If the characters match, no additional cost
                cur[j] = prev[j - 1];
            }
            else
            {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
            }
        }
        prev = cur; // Update the previous row with the current row
    }

    // The value at cur[m] contains the edit distance
    return cur[m];
}

int main()
{

    return 0;
}