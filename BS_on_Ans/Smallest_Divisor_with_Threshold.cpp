#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<int> nums,int div)
{
	int ans = 0;
	for(int i=0; i<nums.size(); i++)
	{
		ans += ceil((double)nums[i]/div);
	}
	return ans;
}
int smallestDivisor(vector<int>& nums, int threshold) {
	int n = nums.size();
	int maxi = INT_MIN;
	for(int i=0; i<n; i++)
	{
		maxi = max(maxi,nums[i]);
	}
	int low = 1;
	int high = maxi,mid,ans=-1;
	while(low <= high)
	{
		mid = (low + high)/2;
		int val = solve(nums,mid);
		if(val <= threshold)
		{
			ans = mid;
			high = mid-1;
		}
		else
			low = mid+1;
	}
	return ans;
}

int main()
{
	vector<int> arr = {1,2,5,9};
	int th = 6;
	int ans = smallestDivisor(arr,th);
	cout<<ans<<endl;
	return 0;
}