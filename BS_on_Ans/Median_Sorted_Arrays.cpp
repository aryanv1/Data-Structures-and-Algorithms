#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute force - Merge both arrays into single array and find median
// Better - Instead of merging into single array just keep trach of median using indexes - while merging we use index on both arrays, use these index to find median
// Both takes O(n1+n2) time 
double MedianOfArrays(vector<int>& a1, vector<int>& a2)
{
	int n1 = a1.size();
	int n2 = a2.size();
	int n = n1+n2;
	if(n1 > n2) return MedianOfArrays(a2,a1);
	int low = 0;
	int high = n1;
	int left = (n1+n2+1)/2;
	while(low <= high)
	{
		int mid1 = (low + high)/2;
		int mid2 = left - mid1;
		int l1 = INT_MIN,l2 = INT_MIN;
		int r1 = INT_MAX, r2 = INT_MAX;
		if(mid1 < n1) r1 = a1[mid1];
		if(mid2 < n2) r2 = a2[mid2];
		if(mid1 - 1 >= 0) l1 = a1[mid1-1];
		if(mid2 - 1 >= 0) l2 = a2[mid2-1];
		if(l1 <= r2 && l2 <= r1)
		{
			if(n%2 == 1)
				return max(l1,l2);
			else
				return ((double)(max(l1,l2)) + (double)(min(r1,r2)))/2.0;
		}
		else if(l1 > r2)
			high = mid1-1;
		else
			low = mid1+1;
	}
	return 0;
}

int main()
{
	vector<int> arr1 = {1,5,9};
	vector<int> arr2 = {2,3,6,7};
	double ans = MedianOfArrays(arr1,arr2);
	cout<<ans<<endl;
	return 0;
}

// Time Complexity - O(min(log(m),log(n)))