#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<int> w, int n, int mid)
{
	int ans = 0;
	int day = 1;
	for(int i=0; i<n; i++)
	{
		if(ans + w[i] > mid)
		{
			day = day + 1;
			ans = w[i];
		}
		else
		{
			ans += w[i];
		}
	}
	return day;
}
int shipWithinDays(vector<int>& weights, int days) {
	int n = weights.size();
	int sum = 0;
	int maxi = 0;
	for(int i=0; i<n; i++)
	{
		maxi = max(maxi,weights[i]);
		sum += weights[i];
	}
	int low = maxi;
	int high = sum;
	int ans = 0;
	while(low <= high)
	{
		int mid = (low + high)/2;
		int d = solve(weights,n,mid);
		if(d <= days)
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
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	int days = 5;
	int ans = shipWithinDays(v,days);
	cout<<ans<<endl;
	return 0;
}