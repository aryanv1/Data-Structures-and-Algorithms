#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minAddToMakeValid(string s) {
	int n = s.size();
	int cnt = 0;
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		if(s[i] == '(')
			cnt++;
		else
			cnt--;

		if(cnt < 0)
		{
			cnt = 0;
			ans++;
		}
	}
	ans += cnt;
	return ans;
}

int main()
{
	
	return 0;
}