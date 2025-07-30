#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(2^N)
void solve(int ind,vector<int> &arr, int n, int target, vector<vector<int>> &ans, vector<int> &out)
{
	if(ind == n)
	{
		if(target == 0)
			ans.push_back(out);
		return;
	}
	//pick the element
	if(arr[ind] <= target)
	{
		out.push_back(arr[ind]);
		solve(ind+1,arr,n,target-arr[ind],ans,out);
		//backtracking
		out.pop_back();
	}
	//donot pick the element
	solve(ind+1,arr,n,target,ans,out);
}

int main()
{
	vector<int> arr = {2,3,6,7};
	int target = 7;
	vector<vector<int>> ans;
	vector<int> out;
	int n = arr.size();
	solve(0,arr,n,target,ans,out);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}