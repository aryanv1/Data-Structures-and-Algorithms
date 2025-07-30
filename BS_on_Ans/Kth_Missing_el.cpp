#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// O(n) solution
int missingK(vector < int > vec, int n, int k) 
{
	for(int i=0; i<n; i++)
	{
		if(vec[i] <= k)
			k++;
		else break;
	}
	return k;
}

// O(log(n)) solution -> Not Binary search on Answers
int findKthPositive(vector<int>& arr, int k) 
{
	int n = arr.size();
	int low = 0;
	int high = n-1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		int missing = arr[mid] - (mid+1);
		if(missing < k)
			low = mid + 1;
		else 
		high = mid - 1;
	}
	return low + k;
        // or we can return high + 1 + k
}
// Ideally at any array position (i+1) number should be there.
// So at each index we can find out that how many number are missing by just subtracting the present value with (i+1)
// Now perform BS on this missing number array(hypothetical)
// At end high will be at position greater than k and low at position less than k

int main()
{
	vector<int> arr = {2,3,4,7,11};
	int k = 5;
	int ans = findKthPositive(arr,k);
	cout<<ans<<endl;
	return 0;
}

/* arr->     {2, 3, 4, 7, 11}
   ind->     {0, 1, 2, 3, 4}
   missing-> {1, 1, 1, 3, 6} missing = arr[i] - (i+1)
   ideally (i+1) should present at index i but some different number is there so we can find it like this
   we perform binary search on this missing array
   we are returning low + k because when high will cross low then it might be the case that low is at 0 and high at -1 so typically we should return 
   arr[high] + more and more = k-missing[high]
   arr[high] + k - missing[high]
   arr[high] + k - (arr[high] - (high+1))
   arr[high] + k - arr[high] + high + 1
   => high + k + 1
   low + 1 = high => low + k is also valid answer
 */