#include <bits/stdc++.h>
using namespace std;
#define ll long long int

static bool comp(vector<int> i1, vector<int> i2)
{
	return i1[1] < i2[1];
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int n = intervals.size();
	sort(intervals.begin(),intervals.end(),comp);
	vector<int> p = intervals[0];
	int cnt = 1;
	for(int i=1; i<n; i++)
	{
		if(intervals[i][0] >= p[1])
		{
			cnt++;
			p = intervals[i];
		}
	}
	return n - cnt;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(NlogN)
// Space Compexity - O(1)
// Inverse of N meetings in one room problem -> there we have to find max meetings and here it is inverse i.e, minimum removal