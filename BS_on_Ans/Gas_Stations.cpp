#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute Force - Time Complexity - O(N*k), Space Complexity - O(n)
double findSmallestMaxDist1(vector<int> &stations, int k) 
{
	int n = stations.size();
	vector<int> howMany(n-1,0);
	// finding maximum difference between any two gasstations
	for (int gasStation = 0; gasStation < k; ++gasStation)
	{
		long double maxSection = -1;
		int maxInd = -1;
		for(int i=0; i<n-1; i++)
		{
			long double diff = stations[i+1] - stations[i];
			long double sectionLen = diff / (long double)(howMany[i]+1);
			if(sectionLen > maxSection)
			{
				maxSection = sectionLen;
				maxInd = i;
			}
		}
		howMany[maxInd]++;
	}
	long double maxAns = -1;
	for (int i = 0; i < n-1; ++i)
	{
		long double diff = stations[i+1] - stations[i];
		long double sectionLen = diff / (long double)(howMany[i]+1);
		maxAns = max(maxAns,sectionLen);
	} 
	return maxAns;
}

// Optimal - Time Complexity - O(NlogN + KlogN), Space Complexity - O(N)
double findSmallestMaxDist2(vector<int> &stations, int k)
{
	int n = stations.size();
	vector<int> howmany(n-1,0);
	priority_queue<pair<long double,int>> pq;
	for(int i=0; i<n-1; i++)
		pq.push({stations[i+1]-stations[i],i});

	for(int i=1; i<=k; i++)
	{
		auto it = pq.top();
		pq.pop();
		int ind = it.second;
		howmany[ind]++;
		long double oldsec = stations[ind+1] - stations[ind];
		long double newsec = (oldsec/(long double)(howmany[ind] + 1));
		pq.push({newsec,ind});
	}
	return pq.top().first;
}

int main()
{
	
	return 0;
}