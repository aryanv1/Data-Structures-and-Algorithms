#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxScore(vector<int>& cardPoints, int k) 
{
	int n = cardPoints.size();
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += cardPoints[i];
	int s = 0;
	int j=0,ans = 0;
	for(int i=0; i<n; i++)
	{
		s += cardPoints[i];
		if(i-j+1 > n-k)
		{
			s -= cardPoints[j];
			j++;
		}
		if(i-j+1 == n-k)
			ans = max(ans,sum-s);
	}
	return ans;
}

int main()
{
	vector<int> arr = {1,2,3,4,5,6,1};
	int k = 3;
	int ans = maxScore(arr,k);
	cout<<ans<<endl;
	return 0;
}

// slide the window of n-k to get k elements from first and last