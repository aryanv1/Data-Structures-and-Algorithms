#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long solve(vector<int>& bt) 
{
	int n = bt.size();
	sort(bt.begin(),bt.end());
	int sum = 0;
	int ans = 0;
    // every process takes the sum of processes before it(waiting time) to get started
    // first process takes 0 time
	for(int i=1; i<n; i++)
	{
		sum += bt[i-1];
		ans += sum;
	}
	return ans/n;
}

int main()
{
	
	return 0;
}