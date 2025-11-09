#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Lower Bound - closest element greater or equal to given element
// int idx = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
int lowerBound(vector<int> &arr, int k) {
	int low = 0;
	int high = arr.size()-1;
	int ans = arr.size();
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(arr[mid] >= k)
		{
			ans = mid;
			high = mid-1;
		}
		else
			low = mid+1;
	}
	return ans;
}

// Upper Bound - closest element greater than given element
// int idx = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
int upperBound(vector<int> &arr, int k) {
	int low = 0;
	int high = arr.size()-1;
	int ans = arr.size();
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(arr[mid] > k) // Just remove equals to
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
	
	return 0;
}