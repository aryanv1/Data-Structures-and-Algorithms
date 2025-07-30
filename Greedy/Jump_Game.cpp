#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// from every index we can reach upto a maximum
// if we cannot touch to any index than we return false
// It happens when our i will cross the maximum index we can reach
bool canJump(vector<int>& nums) {
	int n = nums.size();
	int maxJump = 0;
	for(int i=0; i<n; i++)
	{
		if(i > maxJump)
			return false;
		maxJump = max(maxJump,i+nums[i]);
	}
	return true;
}

// Jump Game - 2 -> Min steps to reach end
int jump(vector<int>& nums) {
	int n = nums.size();
	int l=0,r=0;
	int jumps = 0;
    // less than n-1 because we don't have to consider the last range  otherwise one more jump going out of n will be counted
	while(r < n-1)
	{
		int farthest = 0;
		for(int i=l; i<=r; i++)
			farthest = max(farthest,i+nums[i]);
		l = r+1;
		r = farthest;
		jumps++;
	}
	return jumps;
}
// Here we are taking farthest index till where we can go

int main()
{
	
	return 0;
}