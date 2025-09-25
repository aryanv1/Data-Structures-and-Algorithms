#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Two-pass method (forward + backward) shrink
// Time Complexity - O(n*m) nearly
// Space Complexity - O(1)
string minWindow(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int minLen = INT_MAX, start = -1;

    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[0])
        {
            int j = 0, k = i;

            // forward scan to match s2
            while (k < n && j < m)
            {
                if (s1[k] == s2[j])
                    j++;
                k++;
            }

            if (j == m)
            {
                // backward scan to shrink window
                int end = k - 1;
                j = m - 1;
                while (end >= i)
                {
                    if (s1[end] == s2[j])
                        j--;
                    if (j < 0)
                        break;
                    end--;
                }
                if (minLen > (k - (end + 1)))
                {
                    minLen = k - (end + 1);
                    start = end + 1;
                }
            }
        }
    }

    return (start == -1) ? "" : s1.substr(start, minLen);
}

int main()
{
    string s = "geeksforgeeks";
    string t = "eksrg";
    string ans = minWindow(s, t);
    cout << ans << endl;
    return 0;
}