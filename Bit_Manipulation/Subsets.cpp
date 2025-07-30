#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> subsets(vector<int>& nums) 
{
	int n = nums.size();
	vector<vector<int>>v;
	int total_subsets = 1 << n; // -> 2^n subsets for array of size n
	for(int num=0; num<total_subsets; num++)
	{
		vector<int> temp;
		for(int i=0; i<n; i++)
		{
			if(num & (1<<i))
				temp.push_back(nums[i]);
		}
		v.push_back(temp);
	}
	return v;
}

int main()
{
	vector<int> nums = {1,2,3};
	vector<vector<int>> ans = subsets(nums);
	for(int i=0; i<ans.size(); i++)
	{
		for(int j=0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
// Time Complexity - O(n*2^n)
// Space COmplexity - O(2^n subsets * n (nearly size of each subset))

// for n = 3;
// there will 0, 1, 2 positions which can also indicate bit position
// so for very bit position we can compute to pick it or not using 
// each subset i.e, for n=3 subsets will be 0 to 2^3-1
// 0 - 000 not pick any index, 2 - 010 pick 1st index similarly