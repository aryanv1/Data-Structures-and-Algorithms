#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(string d, int ind, vector<string> &v, string &out, string map[])
{
	if(ind >= d.size())
	{
		v.push_back(out);
		return ;
	}
	int number = d[ind] - '0';
	string val = map[number];
	for(int i=0; i<val.size(); i++)
	{
		out.push_back(val[i]);
		solve(d,ind+1,v,out,map);
		out.pop_back();
	}
}   

vector<string> letterCombinations(string digits) {
	vector<string> v;
	string out;
	string map[10] = 
	{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	solve(digits,0,v,out,map);
	if(digits.size() == 0)
		return {};
	return v;
}

int main()
{
	string digits = "324";
	vector<string> ans = letterCombinations(digits);
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<endl;
	return 0;
}