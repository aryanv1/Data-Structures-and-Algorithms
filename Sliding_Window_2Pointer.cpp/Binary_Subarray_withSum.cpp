#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int less_than_equal_goal(vector<int> &nums, int goal, int n)
{
    if(goal < 0) return 0; // when we will pass goal-1 below and goal is 0
    int i=0,j=0;
    int sum = 0;
    int ans = 0;
    while(j<n)
    {
    	sum += nums[j];
    	while(sum > goal)
    	{
    		sum -= nums[i];
    		i++;
    	}
    	if(sum <= goal)
    		ans += (j-i+1);
    	j++;
    }
    return ans;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
	int n = nums.size();
	int x = less_than_equal_goal(nums,goal,n);
	int y = less_than_equal_goal(nums,goal-1,n);
	return x-y;
}

int main()
{
	int goal;
	vector<int> nums = {1,0,1,0,1};
	goal = 2;
	int ans = numSubarraysWithSum(nums,goal);
	cout<<ans<<endl;
	return 0;
}

// Time Complexity - O(4*N)
// Space COmplexity - O(1)

// Similar question can be formed where we are asked to find subarrays with k odd numbers......here we can simply do this by replacing odd number with 1 and even with 0 and thus find for sum == k.