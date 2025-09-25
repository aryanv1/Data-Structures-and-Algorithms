#include <bits/stdc++.h>
using namespace std;
#define ll long long int
	
int numberOfSubstrings(string s) 
{
	int n = s.size();
	int arr[3] = {-1,-1,-1};
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		arr[s[i]-'a'] = i;
		// Number of subarrays ending at min index of a,b,c
		// Number of elements before it will be part of answer
		if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1)
		{
			ans += 1 + min(arr[0],min(arr[2],arr[1]));
		}
	}
	return ans;
}

int main()
{
	string s = "abcabc";
	int ans = numberOfSubstrings(s);
	cout<<ans<<endl;
	return 0;
}

// simply calculate the min index from a,b,c and accordingly find number of substrings it can form before it

// In O(n^2) solution we can have a slight modification -> whenever we get all the three characters while checking from a particular index, then no need to traverse whole array, as we know that rest of the array will be part of our answer so just add n-j to answer and break out.