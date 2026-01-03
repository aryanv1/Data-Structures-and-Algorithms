#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// Here we are counting all square submatrices with all ones
// Logic is we are using dp to store count of square submatrices with all ones
// ending at that cell. If the cell has value 1, we take minimum of top, left
// and top-left diagonal cell values in dp and add 1 to it.
int countSquares(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = matrix[i][j];
            else
            {
                if (matrix[i][j] == 1)
                {
                    int a = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    dp[i][j] = a + 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            ans += dp[i][j];
        }
    }
    return ans;
}

int main()
{

    return 0;
}