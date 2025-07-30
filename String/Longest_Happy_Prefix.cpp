#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// finding lps for the string
string longestPrefix(string s) {
	int n = s.size();
	vector<int> lps(n,0);
	for(int i=1; i<n; i++)
	{
		int j = lps[i-1];

		while(j>0 && s[i] != s[j])
			j = lps[j-1];

		if(s[i] == s[j])
			j++;

		lps[i] = j;
	}
	return s.substr(0,lps[n-1]);
}

int main()
{
	
	return 0;
}