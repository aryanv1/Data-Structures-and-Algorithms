#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Use the code from Subset_Sum_Target.cpp and Partition_Equal_Subset.cpp
// We will use tabulation method to solve this problem
// Here in the last row of the dp table, we will find that whether that particular sum
// can be formed or not after trversing whole array. If it is true then
// we will calculate the min difference of sum of two subsets

int solve(int n, vector<int> &arr)
{
    int sum = 0;
    for (auto it : arr)
        sum += it;

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool notTaken = dp[i - 1][target];
            bool taken = false;
            if (arr[i] <= target)
            {
                taken = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = notTaken || taken;
        }
    }

    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= sum; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            int s2 = sum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }
    return minDiff;
}

int main()
{

    return 0;
}