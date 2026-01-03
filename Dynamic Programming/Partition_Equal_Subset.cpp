#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)
bool solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == 0)
        return nums[0] == target;
    if (dp[i][target] != -1)
        return dp[i][target];
    int nottake = solve(i - 1, target, nums, dp);
    int take = false;
    if (nums[i] <= target)
        take = solve(i - 1, target - nums[i], nums, dp);
    return dp[i][target] = nottake || take;
}

// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum) -> No Recursion Stack
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (auto it : nums)
        sum += it;
    if (sum % 2 == 1)
        return false;
    vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, 0));
    // return solve(n - 1, sum / 2, nums, dp);

    if (sum / 2 >= nums[0])
        dp[0][nums[0]] = 1;
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sum / 2; s++)
        {
            int nottake = dp[i - 1][s];
            int take = false;
            if (nums[i] <= s)
                take = dp[i - 1][s - nums[i]];
            dp[i][s] = take || nottake;
        }
    }
    return dp[n - 1][sum / 2];
}

int main()
{

    return 0;
}