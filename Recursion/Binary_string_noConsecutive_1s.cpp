#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(char prev, vector<string> &ans, string s, int n)
{
	if(s.size() == n)
	{
		ans.push_back(s);
		return ;
	}
	if(prev == '0')
	{
		s.push_back('0');
		solve('0',ans,s,n);
		s.pop_back();

		s.push_back('1');
		solve('1',ans,s,n);
		s.pop_back();
	}
	else
	{
		s.push_back('0');
		solve('0',ans,s,n);
		s.pop_back();
	}
}
vector<string> generateBinaryStrings(int n)
{
	vector<string> ans;
	string s = "";
    solve('0',ans,s+'0',n); // string starting with 0
    solve('1',ans,s+'1',n); // string starting with 1
    return ans;
}

int main()
{
	int n = 3;
	vector<string> ans = generateBinaryStrings(n);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}