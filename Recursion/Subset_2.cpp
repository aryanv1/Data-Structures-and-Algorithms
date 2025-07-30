#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int ind,vector<int> &arr,vector<vector<int>> &ans,vector<int> &out)
{
	ans.push_back(out);
	for (int i = ind; i < arr.size(); ++i)
	{
		if(i!=ind && arr[i] == arr[i-1]) continue;
		out.push_back(arr[i]);
		solve(i+1,arr,ans,out);
		out.pop_back();
	}
}

int main()
{
	vector<int> arr = {1,2,2};
	vector<vector<int>> ans;
	vector<int> out;
	sort(arr.begin(),arr.end());
	solve(0,arr,ans,out);
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}