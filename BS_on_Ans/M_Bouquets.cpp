#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool possible(vector<int> arr,int m,int k,int day)
{
	int cnt = 0;
	int ans = 0;
	for(int i=0; i<arr.size(); i++)
	{
		if(arr[i] <= day)
			cnt++;
		else
		{
			ans += cnt/k;
			cnt = 0;
		}
	}
	ans += cnt/k;
	return (ans >= m);
}
int minDays(vector<int>& arr, int m, int k) {
	int n = arr.size();
	int maxi = INT_MIN;
	int mini = INT_MAX;
	for(int i=0; i<n; i++)
	{
		maxi = max(maxi,arr[i]);
		mini = min(mini,arr[i]);
	}
	if((long long)m*k > (long long)n) return -1;
	long long low = mini;
	long long high = maxi;
	long long ans = maxi;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(possible(arr,m,k,mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return ans;
}

int main()
{
	vector<int> arr = {1,10,3,10,2};
	int m = 3;
	int k = 1;
	int ans = minDays(arr,m,k);
	cout<<ans<<endl;
	return 0;
}