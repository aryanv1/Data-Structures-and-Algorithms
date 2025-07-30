#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(N)
// For the case of zero in the array, always move to next iteration taking 1 instead in order to get a subarray around 0's
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1;
    int suf = 1;
    int maxi = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(pre == 0) pre = 1; // checks for its previous iteration
        if(suf == 0) suf = 1;
        pre *= nums[i];
        suf *= nums[n-i-1];
        maxi = max(maxi,pre);
        maxi = max(maxi,suf);
    }
    return maxi;
}

int main()
{
	
	return 0;
}