#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string shortestPalindrome(string s) {
    int n = s.size();
    
    // Find the Longest Palindrome Substring in s+'#'+s -> Using lps of KMP
    // Reverse the remaining elements

    string w = s;
    reverse(w.begin(),w.end());
    string t = s + '#' + w; // added '#' in order to differentiate -> eg. if s = aaa then our suffix and prefix will be string itself so our final answer will gets double in this case
    vector<int> lps(2*n+1,0);
    int maxi = 0;
    for(int i=1; i<2*n+1; i++)
    {
        int j = lps[i-1];

        while(j>0 && t[i] != t[j])
        j = lps[j-1];

        if(t[i] == t[j])
        j++;

        lps[i] = j;
    }
    maxi = lps[2*n];
    w = s.substr(maxi,n-maxi);
    reverse(w.begin(),w.end());
    return w + s;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(N)