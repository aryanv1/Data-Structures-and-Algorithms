#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// If our mid is onincreasing slope than go right side else left side
// In case of mid where both sides are increasing we can go any side
int findPeakElement(vector<int>& arr) {
   int n = arr.size();
   if(n == 1) return 0;
   if(arr[n-1] > arr[n-2]) return n-1;
   if(arr[0] > arr[1]) return 0;
   int low = 1;
   int high = n-2;  
   while(low <= high)
   {
       int mid = (low+high)/2;
       if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
       return mid;
       else if(arr[mid] > arr[mid-1])
       low = mid+1;
       else if(arr[mid] > arr[mid+1])
       high = mid-1;
       else // when have multiple peaks, eliminate any one part and in other we'll find peak for sure 
       high = mid-1;
       // Just for understanding written else part otherwise we can combine last two else statements under else
   }
   return -1;
}

int main()
{
	
	return 0;
}