#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n*m)
// Space Complexity: O(m)
// Here we are finding Longest Common Increasing Subsequence
// Logic is we are calculating LIS on array b for every element in array a
// and maintaining maximum length of increasing subsequence found
// so far for elements smaller than current element of a
int LCIS(vector<int> &a, vector<int> &b)
{
    // code here
    int n = a.size();
    int m = b.size();
    vector<int> dp(m, 0);
    for (int i = 0; i < n; i++)
    {
        int maxCount = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
                dp[j] = maxCount + 1; // Whenever we encounter element equal to a[i]
            // we would be having maxCount among LIS of all elements smaller than this element
            else if (a[i] > b[j])
                maxCount = max(maxCount, dp[j]); // getting maxLen of elements smaller than a[i]
                                                 // so we can add it when we encounter a[i]
        }
    }
    // Calculating maximum among all lengths stored in dp array
    int ans = 0;
    for (auto i : dp)
        ans = max(ans, i);
    return ans;
}

int main()
{

    return 0;
}