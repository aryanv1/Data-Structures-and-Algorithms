#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Here we are jsut maintianing a count array to count number of LIS
// If same length found, we add the count of previous index to current index
// else we inherit the count
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (1 + dp[j] > dp[i])
                {
                    // Inherit the count
                    count[i] = count[j];
                    dp[i] = 1 + dp[j];
                }
                else if (1 + dp[j] == dp[i])
                    count[i] += count[j]; // inrease the count
            }
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            ans += count[i];
    }
    return ans;
}

int main()
{

    return 0;
}