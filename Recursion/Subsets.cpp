#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time - O(N*2^N)
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>v;
    // solve(nums,nums.size(),0,v,d);
    // return v;
    int total_subsets = 1 << n;
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
	
	return 0;
}