#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Sorted array have all elements twice except one, find that element
// All pairs before single element will have index (even,odd) and after ones will have index (odd,even)
// On this basis we can figure out the side on which single element will present
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    int low = 1;
    int high = n-2;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
        return nums[mid];
        // we are on left side
        if( (mid%2 == 1 && nums[mid] == nums[mid-1]) || 
                (mid%2 == 0 && nums[mid] == nums[mid+1]) )
                low = mid+1;
        else if( (mid%2 == 1 && nums[mid] == nums[mid+1]) || 
                (mid%2 == 0 && nums[mid] == nums[mid-1]))
                high = mid-1;
    }
    return -1;
}

int main()
{
	
	return 0;
}