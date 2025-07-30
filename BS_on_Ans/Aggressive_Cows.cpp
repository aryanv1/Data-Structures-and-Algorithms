#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(nlogn + nog(max-min))
bool can_place(vector<int> arr,int n, int k, int mid)
{
	int c = 1;
	int ind = 0;
	for(int i=1; i<n; i++)
	{
		if(arr[i] - arr[ind] >= mid)
		{
			c++;
			ind = i;
		}
		if(c == k) return true;
	}
	return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
	int n = stalls.size();
	sort(stalls.begin(),stalls.end());
	int ans = 0;
	int low = 1;
	int high = stalls[n-1] - stalls[0];
	while(low <= high)
	{
		int mid = (low + high)/2;
		bool cp = can_place(stalls,n,k,mid);
		if(cp)
		{
			ans = mid;
			low = mid+1;
		}
		else 
		high = mid-1;
	}
	return ans;
}

int main()
{
	vector<int> arr = {4,2,1,3,6};
	int k = 2;
	int ans = aggressiveCows(arr,k);
	cout<<ans<<endl;
	return 0;
}