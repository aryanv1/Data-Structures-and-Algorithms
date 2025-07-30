#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string longestPalindrome(string s) {
	if(s.size() <= 1) return s;
	int n = s.size();
	int st = 0;
	int maxlen = 0;
	for(int i=0; i<n; i++)
	{
        //odd size palindrome
		int l = i, r = i;
		while(l>=0 && r<n && s[l] == s[r])
		{
			l--;
			r++;
		}
		if(r-l-1 > maxlen)
		{
			maxlen = r-l-1;
			st = l+1;
		}

        //even size palindrome
		l = i, r = i+1;
		while(l>=0 && r<n && s[l] == s[r])
		{
			l--;
			r++;
		}
		if(r-l-1 > maxlen)
		{
			maxlen = r-l-1;
			st = l+1;
		}
	}
	return s.substr(st,maxlen);
}

int main()
{
	
	return 0;
}