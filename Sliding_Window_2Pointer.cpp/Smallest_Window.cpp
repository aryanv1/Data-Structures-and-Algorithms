#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    int hash[26] = {0};
    for (int i = 0; i < m; i++)
        hash[t[i]-'A']++;
    int minlen = INT_MAX;
    int j = 0, cnt = 0, ind = -1;
    for (int i = 0; i < n; i++) 
    {
        if (hash[s[i]-'A'] > 0) // indicates there is still an element to get
            cnt++;
        hash[s[i]-'A']--;
        while (cnt == m) 
        {
            if (i - j + 1 < minlen) 
            {
                minlen = i - j + 1;
                ind = j;
            }
            hash[s[j]-'A']++;
            if (hash[s[j]-'A'] > 0) // +ve freq indicates we found a char of t string which is eliminated from substring
                cnt--;
            j++;
        }
    }
    if (ind == -1)
        return "-1";
    return s.substr(ind, minlen);
}

int main()
{
	string s = "timetopractice";
	string t = "toc";
	string ans = smallestWindow(s,t);
	cout<<ans<<endl;
	return 0;
}