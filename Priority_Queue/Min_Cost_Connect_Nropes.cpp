#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long minCost(long long arr[], long long n) 
{
	if(n == 1) return 0;
	priority_queue<long long,vector<long long>,greater<long long>> pq;
	for(long long i=0; i<n; i++)
		pq.push(arr[i]);
	long long ans = 0;
	while(!pq.empty())
	{
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		ans += a+b;
		if(!pq.empty())
			pq.push(a+b);
	}
	return ans;
}

int main()
{
	
	return 0;
}

// Take the smaller ropes first and add them