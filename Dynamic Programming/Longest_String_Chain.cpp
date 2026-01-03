#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(N^2)
// Space Complexity: O(N)
static bool comp(const string &a, const string &b)
{
    return a.size() < b.size();
}
bool isPossible(string &a, string &b)
{
    if (a.size() != b.size() + 1)
        return false;
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    while (i < n)
    {
        if (j < m && a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return (i == n && j == m);
}
int longestStrChain(vector<string> &words)
{
    int n = words.size();
    vector<int> dp(n, 1);
    sort(words.begin(), words.end(), comp);
    for (auto it : words)
        cout << it << " ";
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (isPossible(words[i], words[j]) && 1 + dp[j] > dp[i])
                dp[i] = 1 + dp[j];
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}

int main()
{

    return 0;
}