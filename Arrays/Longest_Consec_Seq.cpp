#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(N) -> optimal solution
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int maxlen = 0;
    unordered_set<int> s(nums.begin(),nums.end());
    for(int i=0; i<n; i++)
    {
        if(s.find(nums[i]-1) == s.end())
        {
            int el = nums[i];
            int len = 1;
            while(s.find(el+1) != s.end())
            {
                len++;
                el++;
            }
            maxlen = max(maxlen,len);
        }
    }
    return maxlen;
}

// Time Complexity - O(NlogN) -> better solution
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}

int main()
{
	
	return 0;
}