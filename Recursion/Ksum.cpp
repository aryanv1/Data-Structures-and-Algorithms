#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool solve(int ind, vector<int> &v, vector<vector<int>> &ans, vector<int> &out,int &sum,int k,int n)
{
	if(ind == n)
	{
		if(sum == k)
		{
			ans.push_back(out);
			return true;/////
		}
		else/////
			return false;/////
	}
	out.push_back(v[ind]);
	sum += v[ind];
	if(solve(ind+1,v,ans,out,sum,k,n) == true) return true;///
	sum -= v[ind];
	out.pop_back();
	if(solve(ind+1,v,ans,out,sum,k,n) == true) return true;////
	else
	return false;///// -> these all are changes we need to do if we want to print only one array
}

int main()
{
	int n = 3;
	vector<int> v = {1,2,1};
	vector<int> out;
	vector<vector<int>> ans;
	int sum = 0;
	int k = 2;
	bool f = solve(0,v,ans,out,sum,k,n);
	for(int i=0; i<ans.size(); i++)
	{
		for(int j=0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}