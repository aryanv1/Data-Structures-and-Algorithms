#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestOnes(vector<int>& nums, int k) 
{
	int n = nums.size();
	int i=0,j=0,p=0;
	int cnt = 0;
	int maxlen = 0;
	while(j<n)
	{
		if(nums[j] == 0)
		{
			cnt++;
		}
		if(cnt > k)
		{
			if(nums[i] == 0)
				cnt--;
			i++;
		}
		if(cnt <= k)
			maxlen = max(maxlen,j-i+1);
		j++;
	}
	maxlen = max(maxlen,j-i);
	return maxlen;
}

int main()
{
	vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
	int k = 2;
	int len = longestOnes(nums,k);
	cout<<len<<endl;
	return 0;
}

// Time Comlpexity - O(N)
// Space Complexity - O(1)