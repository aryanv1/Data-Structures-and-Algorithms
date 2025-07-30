#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	int n = nums.size();
	deque<int> dq;
	vector<int> ans;
	for(int i=0; i<n; i++)
	{
		if(!dq.empty() && dq.front() <= i-k) // Only consider the elements in the window size of k
			dq.pop_front();

		while(!dq.empty() && nums[dq.back()] <= nums[i]) // we have to maintain monotonic decreasing stack 
			dq.pop_back();

		dq.push_back(i);
		if(i >= k-1) // Push when the window size becomes equal to k
			ans.push_back(nums[dq.front()]);
	}
	return ans;
}

int main()
{
	int k = 3;
	vector<int> arr = {1,3,-1,-3,5,3,6,7};
	vector<int> ans = maxSlidingWindow(arr,k);
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

// Time Complexity - O(n)
// Space Complexity - O(n)