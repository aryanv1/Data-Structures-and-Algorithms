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

int main()
{
	string digits;
	cin>>digits;
	vector<string> v;
	string out;
	string map[10] = 
			{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	solve(digits,0,v,out,map);
	for(int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}