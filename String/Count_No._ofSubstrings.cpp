#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long solve(string s, int k)
{
	int n = s.size();
	int l = 0,cnt = 0;
	int ans = 0;
	vector<int> mp(26,0);
	for(int r=0; r<n; r++)
	{
		mp[s[r]-'a']++;
		if(mp[s[r]-'a'] == 1) cnt++;
		while(cnt>k)
		{
			mp[s[l]-'a']--;
			if(mp[s[l]-'a'] == 0)
				cnt--;
			l++;
		}
		ans += r-l+1;
	}
	return ans;
}
long long int substrCount (string s, int k) {
    	//code here.
	long long k1 = solve(s,k);
	long long k2 = solve(s,k-1);
	return k1-k2;
}

int main()
{
	
	return 0;
}