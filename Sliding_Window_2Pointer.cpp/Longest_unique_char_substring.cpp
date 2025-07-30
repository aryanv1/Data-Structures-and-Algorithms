#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestKSubstr(string s, int k) 
{
	unordered_map<char,int> m;
	int n = s.size();
	int l = 0;
	int r = 0;
	int maxlen = 0;
	while(r<n)
	{
		m[s[r]]++;
		if(m.size() > k)
		{
			m[s[l]]--;
			if(m[s[l]] == 0)
				m.erase(s[l]);
			l++;
		}
		if(m.size() == k)
		{
			maxlen = max(maxlen,r-l+1);
		}
		r++;
	}
	if(maxlen == 0) return -1;
	return maxlen;
}

int main()
{
	string s = "aabacbebebe";
	int k = 3;
	int ans = longestKSubstr(s,k);
	cout<<ans<<endl;
	return 0;
}