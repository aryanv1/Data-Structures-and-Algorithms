#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(N)
void sortColors(vector<int>& arr) {
    int n = arr.size();
    int low = 0,high = n-1;
    int mid = low;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;    
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
	
	return 0;
}