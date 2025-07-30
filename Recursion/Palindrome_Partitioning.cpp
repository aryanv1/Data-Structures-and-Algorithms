#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPalindrome(string s)
{
	int n = s.size();
	for(int i=0; i<n/2; i++)
	{
		if(s[i] != s[n-1-i])
			return false;
	}
	return true;
}

void solve(int ind, string &s, vector<string> &ds, vector<vector<string>> &ans, int n)
{
	if(ind == n)
	{
		ans.push_back(ds);
		return ;
	}
	for(int i=1; i<=n-ind; i++)
	{
		string t = s.substr(ind,i);
		if(isPalindrome(t) == true)
		{
			ds.push_back(t);
			solve(ind+i,s,ds,ans,n);
			ds.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<string>> ans;
	vector<string> ds;
	solve(0,s,ds,ans,s.size());
	return ans;
}

int main()
{
	string s = "aab";
	vector<vector<string>> ans = partition(s);
	for(int i=0; i<ans.size(); i++)
	{
		for(int j=0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}