#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> singleNumber(vector<int>& nums) 
{
    int n = nums.size();
    long long xr = 0;
    for(int i=0; i<n; i++)
        xr = xr ^ nums[i];
    long long k = (xr & (xr-1)) ^ xr; // gives the rightmost set bit
    long long ans1=0,ans2=0;
    for(int i=0; i<n; i++)
    {
        if((nums[i] & k) == 0)
        ans1 = ans1 ^ nums[i];
        else
        ans2 = ans2 ^ nums[i];
    }
    return {(int)ans1,(int)ans2};
}

int main()
{
	vector<int> nums = {1,2,1,3,2,5};
	vector<int> ans = singleNumber(nums);
	cout<<ans[0]<<" "<<ans[1]<<" "<<endl;
	return 0;
}

// Time Complexity - O(n)
// Space Complexity - O(1)

// number & number-1 -> rightmost set bit will be 0 and all right bits will be one and left bits will be as it is
// On XORing this we'll get rightmost set bit