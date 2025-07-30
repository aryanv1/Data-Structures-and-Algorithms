#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//Another Way - Love Babar
/*void solve(int ind, vector<vector<int>> &v, vector<int> nums)
    {
        //base condition
        if(ind >= nums.size())
        {
            v.push_back(nums);
            return ;
        }

        for(int j=ind; j<nums.size(); j++)
        {
            swap(nums[ind],nums[j]);
            solve(ind+1,v,nums);
            //backtracking
            swap(nums[ind],nums[j]);
        }
    }
*/
// Striver
void solve(vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr,int freq[])
{
	if(ds.size() == arr.size())
	{
		ans.push_back(ds);
		return ;
	}
	for(int i=0; i<arr.size(); i++)
	{
		if(freq[i] != 1)
		{
			ds.push_back(arr[i]);
			freq[i] = 1;
			solve(ans,ds,arr,freq);
			freq[i] = 0;
			ds.pop_back();
		}
	}
}

int main()
{
	vector<int> arr = {1,2,3};
	int n = 3;
	vector<vector<int>> ans;
	vector<int> ds;
	int freq[n] = {0};
	solve(ans,ds,arr,freq);
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