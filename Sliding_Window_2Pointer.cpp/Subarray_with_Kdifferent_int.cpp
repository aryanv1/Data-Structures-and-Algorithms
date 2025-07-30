#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int func(int k, vector<int> nums, int n)
{
	unordered_map<int,int> m;
	int i=0,j=0;
	int cnt = 0;
	while(j<n)
	{
		m[nums[j]]++;
		while(m.size() > k)
		{
			m[nums[i]]--;
			if(m[nums[i]] == 0) m.erase(nums[i]);
			i++;
		}
		cnt += j-i+1;
		j++;
	}
	return cnt;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
	int n = nums.size();
	int k1 = func(k,nums,n);
	int k2 = func(k-1,nums,n);
	return k1-k2;
}

int main()
{
	std::vector<int> v = {1,2,1,2,3};
	int k = 2;
	int ans = subarraysWithKDistinct(v,k);
	cout<<ans<<endl;
	return 0;
}