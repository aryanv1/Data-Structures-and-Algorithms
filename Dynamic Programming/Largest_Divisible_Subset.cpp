#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Here we need to find the largest subset such that for every pair (Si, Sj)
// either Si % Sj == 0 or Sj % Si == 0
// So if we sort the array first, then for every element we can check
// divisibility with previous elements only
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    sort(nums.begin(), nums.end());
    int ind = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if ((nums[i] % nums[j] == 0) && (1 + dp[j] > dp[i]))
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            ind = i;
        }
    }
    vector<int> ans;
    ans.push_back(nums[ind]);
    while (hash[ind] != ind)
    {
        ind = hash[ind];
        ans.push_back(nums[ind]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}