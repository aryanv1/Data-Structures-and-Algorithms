#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int solve(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind >= nums.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    // pick
    int pick = nums[ind] + solve(ind + 2, nums, dp);
    // not pick
    int nopick = solve(ind + 1, nums, dp);

    return dp[ind] = max(pick, nopick);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(0, nums, dp);

    /*
        // Tabulation - Time Complexity: O(n)
        // Space Complexity: O(n) // no recursion stack space
        vector<int> dp(n+1, 0);
        dp[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            int pick = nums[i] + dp[i+2];
            int nopick = dp[i+1];

            dp[i] = max(pick,nopick);
        }
        return dp[0];

        // Space Optimized - Time Complexity: O(n)
        // Space Complexity: O(1)
        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]
        int curr = 0;  // dp[i]
        for(int i=n-1; i>=0; i--)
        {
            int pick = nums[i] + next2;
            int nopick = next1;
            curr = max(pick,nopick);
            next2 = next1;
            next1 = curr;
        }
        return curr;

        -> For circular houses, just take max of robbing from 0 to n-2 and 1 to n-1
        -> It is because first and last house are adjacent, so we can't rob both
    */
}

int main()
{

    return 0;
}