#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//can also be solved by inserting 'ans' to set ds and then returning it - in part 1
void solve(int ind,vector<vector<int>> &ans, vector<int> &out,int target,int n,
	vector<int> &arr)
{
	if(target == 0)
	{
		ans.push_back(out);
		return ;
	}
	for(int i=ind; i<n; i++)
	{
		if(i>ind && arr[i] == arr[i-1]) continue;
		if(arr[i] > target) break;
		out.push_back(arr[i]);
		solve(i+1,ans,out,target-arr[i],n,arr);
		out.pop_back();
	}
}

int main()
{
	vector<int> arr = {10,1,2,7,6,1,5};
	int target = 8;
	vector<vector<int>> ans;
	vector<int> out;
	int n = arr.size();
	sort(arr.begin(),arr.end());
	solve(0,ans,out,target,n,arr);
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