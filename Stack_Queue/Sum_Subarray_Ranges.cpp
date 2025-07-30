#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long sum_max(vector<int> &nums, int n)
{
	stack<long long> st,st1;
	vector<long long> lge(n),rge(n);
	for(int i=0; i<n; i++)
	{
		while(!st.empty() && nums[st.top()] < nums[i])
			st.pop();
		if(st.empty())
			lge[i] = i+1;
		else
			lge[i] = i-st.top();
		st.push(i);
	}
	for(int i=n-1; i>=0; i--)
	{
		while(!st1.empty() && nums[st1.top()] <= nums[i])
			st1.pop();
		if(st1.empty())
			rge[i] = n-i;
		else
			rge[i] = st1.top()-i;
		st1.push(i);
	}
	long long ans = 0;
	for(int i=0; i<n; i++)
		ans += (long long)(nums[i]*lge[i]*rge[i]);
	return ans;
}
long long sum_min(vector<int> &nums, int n)
{
	stack<long long> st,st1;
	vector<long long> lse(n),rse(n);
	for(int i=0; i<n; i++)
	{
		while(!st.empty() && nums[st.top()] > nums[i])
			st.pop();
		if(st.empty())
			lse[i] = i+1;
		else
			lse[i] = i-st.top();
		st.push(i);
	}
	for(int i=n-1; i>=0; i--)
	{
		while(!st1.empty() && nums[st1.top()] >= nums[i])
			st1.pop();
		if(st1.empty())
			rse[i] = n-i;
		else
			rse[i] = st1.top()-i;
		st1.push(i);
	}
	long long ans = 0;
	for(int i=0; i<n; i++)
		ans += (long long)(nums[i]*lse[i]*rse[i]);
	return ans;
}
long long subArrayRanges(vector<int>& nums) {
	int n = nums.size();
	long long x = sum_max(nums,n);
	long long y = sum_min(nums,n);
	return x-y;
}

int main()
{
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		nums.push_back(a);
	}
	int ans = subArrayRanges(nums);
	cout<<ans<<endl;
	return 0;
}
// 4,-2,-3,4,1
// Time Complexity - O(N)
// Space Complexity - O(N)