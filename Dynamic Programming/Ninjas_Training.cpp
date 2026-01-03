#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*3)
// Space Complexity: O(n*3)
int solve(int day, vector<vector<int>> &dp, vector<vector<int>> &points, int n, int last)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    if (dp[day][last] != -1)
        return dp[day][last];
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + solve(day - 1, dp, points, n, task);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

// Time Complexity: O(n*3)
// Space Complexity: O(n*3) - No recursion stack space
int maximumPoints(vector<vector<int>> &arr)
{
    // Code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    for (int j = 0; j < 3; j++)
        dp[n - 1][j] = arr[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int prev = 0; prev < 3; prev++)
        {
            if (prev == 0)
                dp[i][prev] = arr[i][0] + max(dp[i + 1][1], dp[i + 1][2]);
            else if (prev == 1)
                dp[i][prev] = arr[i][1] + max(dp[i + 1][0], dp[i + 1][2]);
            else
                dp[i][prev] = arr[i][2] + max(dp[i + 1][0], dp[i + 1][1]);
        }
    }
    return max(dp[0][0], max(dp[0][1], dp[0][2]));
}

int main()
{

    return 0;
}