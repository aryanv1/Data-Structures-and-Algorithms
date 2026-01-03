#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Same que of assigning +1/-1 to numbers to get a target sum

static const int MOD = 1e9 + 7;
int solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (target == 0 && nums[0] == 0)
            return 2;
        if (target == 0 || target == nums[0])
            return 1;
        return 0;
    }

    if (dp[i][target] != -1)
        return dp[i][target];

    int nottake = solve(i - 1, target, nums, dp);
    int take = 0;
    if (nums[i] <= target)
        take = solve(i - 1, target - nums[i], nums, dp);

    return dp[i][target] = (nottake + take) % MOD;
}

// Time Complexity: O(n*target)
// Space Complexity: O(n*target) -> No Recursion Stack
int perfectSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    // return solve(n - 1, target, nums, dp);

    if (nums[0] == 0)
    {
        dp[0][0] = 2; // pick or not pick zero
    }
    else
    {
        dp[0][0] = 1; // not pick // Target is zero but not nums[0]
        if (nums[0] <= target)
            dp[0][nums[0]] = 1; // pick
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int nottake = dp[i - 1][j];
            int take = 0;
            if (nums[i] <= j)
                take = dp[i - 1][j - nums[i]];
            dp[i][j] = (take + nottake) % MOD;
        }
    }
    return dp[n - 1][target];
}

int main()
{

    return 0;
}