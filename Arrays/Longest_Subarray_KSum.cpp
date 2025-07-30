#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(nlogn) -> if used map
// if used unordered_map, then O(n*n) worst case due to find method
int longestSubarray(vector<int>& arr, int k) {
    // code here
    int n = arr.size();
    int maxlen = 0;
    int preSum = 0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++)
    {
        preSum += arr[i];
        if(preSum == k)
            maxlen = max(maxlen, i+1);
        if(m.find(preSum - k) != m.end())
            maxlen = max(maxlen, i-m[preSum - k]);
        if(m.find(preSum) == m.end())
            m[preSum] = i;
    }
    return maxlen;
}

// Optimal Approach if array sonot have negative elements
// Time Complexity - O(2N)
// Second while loop runs for O(N) overall and not for each iteration of First while loop
int longestSubarray2(vector<int>& arr, int k) {
    int sum = 0;
    int n = arr.size();
    int i = 0,j = 0, maxlen = 0;
    while(j < n)
    {
        sum += arr[j];
        while(sum > k && i < j)
        {
            sum -= arr[i];
            i++;
        }
        if(sum == k)
            maxlen = max(maxlen, j-i+1);
        j++;
    }
    return maxlen;
}
// Explanation: Here first we add the elements till it reaches k and if it exceeds k then we simply remove elements from front and along with t calculate the length

int main()
{
	vector<int> arr = {1,2,3,4,5};
	int ans = longestSubarray(arr,9);
	cout<<ans<<endl;
	return 0;
}