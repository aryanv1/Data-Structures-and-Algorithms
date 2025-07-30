#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int kthElement(int a1[], int a2[], int n1, int n2, int k)
{
	int n = n1+n2;
	if(n1 > n2) return kthElement(a2,a1,n2,n1,k);
	int low = max(k-n2,0);
	// if k>n1 and k>n2 then we can't take 0 from a1 otherwise we will not get kth element on left side
	// eg, n1=3,n2=4 and k=5
	int high = min(k,n1);
	// if k<n1 then on left side we don't want more than k elements
	int left = k;
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
			return max(l1,l2);
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
	int arr1[] = {1,5,9};
	int arr2[] = {2,3,6,7};
	int ans = kthElement(arr1,arr2,3,4,3);
	cout<<ans<<endl;
	return 0;
}