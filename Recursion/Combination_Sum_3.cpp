#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int num, vector<vector<int>> &ans, vector<int> &ds, int n, int k)
{
	if(n < 0)
		return ;

	if(k == 0 && n > 0)
		return ;

	if(k == 0 && n == 0)
	{
		ans.push_back(ds);
	}

	for(int i=num+1; i<=9; i++)
	{
		ds.push_back(i);
		solve(i,ans,ds,n-i,k-1);
		ds.pop_back();
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> ans;
	vector<int> ds;
	solve(0,ans,ds,n,k); 
	return ans;
}

int main()
{
	int k = 3,n = 9;
	vector<vector<int>> ans = combinationSum3(k,n);
	for(int i=0; i<ans.size(); i++)
	{
		for(int j=0; j<ans[i].size(); j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}