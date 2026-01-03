#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*n)
// Space Complexity: O(n*n)
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for (int j = 0; j < n; j++)
        dp[0][j] = matrix[0][j];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = j - 1 >= 0 ? dp[i - 1][j - 1] : 1e9;
            int up = dp[i - 1][j];
            int right = j + 1 < n ? dp[i - 1][j + 1] : 1e9;
            dp[i][j] = matrix[i][j] + min(up, min(left, right));
        }
    }
    int ans = 1e9;
    for (int j = 0; j < n; j++)
        ans = min(ans, dp[n - 1][j]);
    return ans;
}

int main()
{

    return 0;
}