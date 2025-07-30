#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string minWindow(string s, string t) 
{
    int n = s.size();
    int m = t.size();
    int minlen = INT_MAX;
    int ind = -1,k = 0,j = 0,i = 0;
    while(i < n)
    {
        if(s[i] == t[k])
        k++;
        if(k == m)
        {
            j = i;
            k--;
            while(j>=0 && k>=0)
            {
                if(s[j] == t[k])
                    k--;
                j--;
            }
            j++;
            if(i-j+1 < minlen)
            {
                minlen = i-j+1;
                ind = j;
            }
            k = 0;
            i = j; // actually j+1 should be there but after this i++ is happening so no issue
            // And we should start from next char from it inorder to find another subsequence -> position of j will not matter
        }
        i++;
    }
    if(ind == -1) return "";
    return s.substr(ind,minlen);
}

int main()
{
	string s = "geeksforgeeks";
	string t = "eksrg";
	string ans = minWindow(s,t);
	cout<<ans<<endl;
	return 0;
}

// Time Complexity - O(n*m) nearly
// Space Complexity - O(1)