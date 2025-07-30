#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxMeetings(int start[], int end[], int n)
{
	vector<pair<int,int>> v;
	for(int i=0; i<n; i++)
	{
		v.push_back({end[i],start[i]});
	}
	// sort according to end time 
	sort(v.begin(),v.end());
	pair<int,int> p = v[0];
	int cnt = 1;
	// check if start time is greater than the end time of prev one
	for(int i=1; i<n; i++)
	{
		if(v[i].second > p.first)
		{
			cnt++;
			p = v[i];
		}
	}
	return cnt;
}

int main()
{
	
	return 0;
}