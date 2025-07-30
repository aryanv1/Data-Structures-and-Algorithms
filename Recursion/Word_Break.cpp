#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Recursive Solution - Time - O(2^n * k) -> k=maxWordLength, Space - O(n)
bool solve(int ind, string &s, unordered_set<string> &st, int n)
{
	if(ind == n)
	{
		return true;
	}
	bool a = false;
	string t = "";
	for(int i=ind; i<n; i++)
	{
		t += s[i];
		if(st.find(t) != st.end())
			a = a | solve(i+1,s,st,n);
	}
	return a;
}
bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string> st;
	int n = wordDict.size();
	int m = s.size();
	for(int i=0; i<n; i++)
	{
		st.insert(wordDict[i]);
	}
	return solve(0,s,st,m);
}

// Tabulation - Time - O(n*m), Space - O(n)
bool wordBreak1(string s, vector<string>& wordDict) {
	int n = s.size();
	int m = wordDict.size();
	vector<int> dp(n+1,0);
	dp[0] = 1;
	for(int i=0; i<=n; i++)
	{
		for(auto word : wordDict)
		{
			if(dp[i] && s.substr(i,word.size()) == word)
				dp[i+word.size()] = true;
		}
	}
	return dp[n];
}

int main()
{
	string s = "leetcode";
	vector<string> w = {"leet","code"};
	bool ans = wordBreak1(s,w);
	cout<<ans<<endl;
	return 0;
}