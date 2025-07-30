#include <bits/stdc++.h>
using namespace std;
#define ll long long int

priority_queue<int,vector<int>,greater<int>> minheap;
int m_k;
KthLargest(int k, vector<int>& nums) {
	m_k=k;
	for(int x:nums)
		add(x);
}

int add(int val) {
	if(minheap.size()<m_k)minheap.push(val);
	else
	{
		if(val>minheap.top()) // maintaining 3 larget element in pq 
		{
			minheap.pop();
			minheap.push(val);
		}
	}
	return minheap.top();
}

int main()
{
	
	return 0;
}