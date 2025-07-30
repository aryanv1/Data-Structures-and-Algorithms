#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute method is by running 3 loops -> O(n*n*n)
// Better method is by using the fact that third = -(first + second)
// Using find method of hashmap and two loops to solve this one -> 
// O(n*n*log(uniqueTriplets))
// Optimal Method - O(nlogn + n*n) 
// n*n will be near about and not exactly 
// Both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0)
            {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if(sum > 0)
                k--;
            else
                j++;
        }
    }
    return ans;
}

int main()
{
	
	return 0;
}