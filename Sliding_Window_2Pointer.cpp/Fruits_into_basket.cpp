#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Using 2 Pointer
int totalFruits(int n, vector<int> &fruits) 
{
	int l=0,r=0;
	int maxlen = 0;
	unordered_map<int,int> m;
	while(r<n)
	{
		m[fruits[r]]++;
		while(m.size() > 2)
		{
			m[fruits[l]]--;
			if(m[fruits[l]] == 0)
				m.erase(fruits[l]);
			l++;
		}
		if(m.size() <= 2)
			maxlen = max(maxlen,r-l+1);
		r++;
	}
	return maxlen;
}
// Time Complexity - O(2*N)

// Using Sliding Window
// Maintaining the window of maxlen
int totalFruit(vector<int>& fruits) 
{
	int n = fruits.size();
	int l=0,r=0;
	int maxlen = 0;
	unordered_map<int,int> m;
	while(r<n)
	{
		m[fruits[r]]++;
		if(m.size() > 2)
		{
			m[fruits[l]]--;
			if(m[fruits[l]] == 0)
				m.erase(fruits[l]);
			l++;
		}
		if(m.size() <= 2)
			maxlen = max(maxlen,r-l+1);
		r++;
	}
	return maxlen;
}
// Time Complexity - O(N)

int main()
{
	vector<int> arr = {1,0,1,4,1,4,1,2,3};
	int ans = totalFruit(arr);
	cout<<ans<<endl;
	return 0;
}