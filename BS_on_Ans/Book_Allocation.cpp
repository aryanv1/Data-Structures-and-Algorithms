#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// we are not applying BS on number of pages, rather of how many students we can allocate 
// No need to worry about exact pages since it will automatically find exact pages
int solve(int arr[],int n,int mid)
{
	int al = 1;
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i] + sum <= mid)
		{
			sum += arr[i];
		}
		else
		{
			sum = arr[i];
			al++;	
		}
	}
	return al;
}
int findPages(int arr[], int n, int m) 
{
	if(m > n) return -1;
	int sum = 0;
	int maxi = INT_MIN;
	for(int i=0; i<n; i++)
	{
		maxi = max(maxi,arr[i]); // then everyone will able to hold atleast one book in case of n students
		sum += arr[i];
	}
	int low = maxi;
	int high = sum;
	int ans = -1;
	while(low <= high)
	{
		int mid = (low+high)/2;
		int allocate = solve(arr,n,mid);
		if(allocate > m)
			low = mid+1;
		else 
            high = mid-1; // our answer will be here so at end low comes to this place and high will go to not possible side
        }
        return low;
    }

    int main()
    {
    	int arr[] = {12,34,67,90};
    	int m = 2;
    	int ans = findPages(arr,4,m);
    	cout<<ans<<endl;
    	return 0;
    }