#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Memoization
// Time Complexity: O(N^2)
// Space Complexity: O(N^2) + O(N) for recursion stack
int solve(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int len = solve(ind + 1, prev, nums, dp);
    if (prev == -1 || nums[ind] > nums[prev])
        len = max(len, 1 + solve(ind + 1, ind, nums, dp));
    return dp[ind][prev + 1] = len;
}

// Tabulation
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return solve(0,-1,nums,dp);
    int maxi = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = 0; prev >= -1; prev--)
        {
            int len = dp[i + 1][prev + 1];
            if (prev == -1 || nums[i] > nums[prev])
                len = max(len, 1 + dp[i + 1][i + 1]);
            dp[i][prev + 1] = len;
        }
    }
    return dp[0][0]; // dp[0][-1+1]
}

// Space Optimization
// Time Complexity: O(N^2)
// Space Complexity: O(N)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    // return solve(0,-1,nums,dp);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}

// Printing LIS
vector<int> printLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);
    int maxi = 0;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    // Reconstructing the LIS
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

// Optimized LIS using Binary Search
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Only to get length of LIS and not the sequence
int lis(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (temp.size() == 0 || temp.back() < arr[i])
            temp.push_back(arr[i]);
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

int main()
{

    return 0;
}