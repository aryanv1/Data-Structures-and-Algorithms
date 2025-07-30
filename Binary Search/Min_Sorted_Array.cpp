#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Just find min of sorted array and compare
// For distinct elements
int findMin(vector<int>& arr) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int mid;
    int ans = INT_MAX;
    while(low <= high)
    {
        mid = (low + high)/2;
        
        /*
			Add this for further optimization
			if(arr[low] <= arr[high]) // Search space is already sorted
				return arr[low];
        */
        
        if(arr[low] <= arr[mid]) // when we are in sorted half -> no need of further binary search
        {
            ans = min(ans,arr[low]);
            low = mid+1;
        }
        else 
        {
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}

// Similar Que: Find how many times the array has been rotated
// For this we just have to find the index of minimum element
// Slight modifications required in below code

int main()
{
	
	return 0;
}