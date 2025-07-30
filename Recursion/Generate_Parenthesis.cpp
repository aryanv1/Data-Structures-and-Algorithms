#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int open, int close, vector<string> &ans, string s, int n)
{
	if(open == n && close == n)
	{
		ans.push_back(s);
		return ;
	}

	if(open < n)
	{
		s.push_back('(');
		solve(open+1,close,ans,s,n);
		s.pop_back();
	}

	if(open > close)
	{
		s.push_back(')');
		solve(open,close+1,ans,s,n);
		s.pop_back();
	}
}
vector<string> AllParenthesis(int n) 
{
        // Your code goes here 
	vector<string> ans;
	string s = "";
	solve(0,0,ans,s,n);
	return ans;
}

int main()
{
	int n = 3;
	vector<string> ans = AllParenthesis(n);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}