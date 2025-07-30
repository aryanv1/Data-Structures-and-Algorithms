#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Rotated from a pivot element and no repeating elements
int search(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == k)
            return mid;
        else if(arr[mid] >= arr[low]) // Left Side is Sorted so search there
        {
            if(k < arr[mid] && k >= arr[low])
                high = mid-1;
            else 
                low = mid+1;
        }
        else // Right side is sorted
        {
            if(k > arr[mid] && k <= arr[high]) 
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}

// Here elements are not distinct
// Edge Case: 0 0 0 0 1 2 3 0 -> low=0, high=0, mid=0
// In this case we should shrink from both ends in order to know the sorted side
// Here worst case can be O(N/2) -> When all elements are same
bool search(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(arr[mid] == k)
            return true;
            if(arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;
                continue;
            }
            // left half sorted
            if(arr[mid] >= arr[low])
            {
                if(k <= arr[mid] && k >= arr[low])
                high = mid-1;
                else
                low = mid+1;
            }
            //right half sorted
            else
            {
                if(k >= arr[mid] && k <= arr[high])
                low = mid+1;
                else
                high = mid-1;
            }
        }
        return false;
    }

int main()
{
	
	return 0;
}