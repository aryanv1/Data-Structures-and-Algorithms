#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int characterReplacement(string s, int k) 
{
	int n = s.size();
	int i=0,j=0;
	unordered_map<char,int> m;
	int maxi = INT_MIN;
	int ans = 0;
	while(j < n)
	{
		m[s[j]]++;
		maxi = max(maxi,m[s[j]]);
		if((j-i+1) - maxi > k)
		{
			m[s[i]]--;
			i++;
            // k = length - max_element -> to keep k same we need to increase length and by one and increase freq of max element by 1 as well so no need to update maximum freq i.e, maxi since we want a freq greater than the current one
		}
		if((j-i+1) - maxi <= k)
			ans = max(ans,j-i+1);
		j++;
	}
	return ans;
}

int main()
{
	string s = "AABAABB";
	int k = 2;
	int ans = characterReplacement(s,k);
	cout<<ans<<endl;
	return 0;
}

// Time Complexity - O(n)
// Space Complexity - O(1)

// here simple solution can be we just find maximum freq element from hashmap again when we shrink the window using while loop(for 2 pointer)