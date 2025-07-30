#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(N)
// Intution is we don't carryforward negative sum since it is going to reduce our total sum
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0, ans = INT_MIN;
    for(int i=0; i<n; i++)
    {
        sum += nums[i];
        ans = max(ans,sum);
        if(sum < 0)
            sum = 0;
    }
    return ans;
}

// Follow Up Question
// If we want the subarray with maximum length
int maxSubArray2(vector<int>& nums) {
    int n = nums.size();
    int start = 0,ansStart = 0, ansEnd = 0;
    int sum = 0, ans = INT_MIN;
    for(int i=0; i<n; i++)
    {
    	if(sum == 0)
    		start = i;

        sum += nums[i];

        if(sum > ans)
        {
        	ans = sum;
        	// Since start variable will change upon further iterations
        	// So need separate variable to keep track of start
        	ansStart = start;
        	ansEnd = i;
        }
        if(sum < 0)
           sum = 0;
    }
    return ans;
}

int main()
{
	
	return 0;
}