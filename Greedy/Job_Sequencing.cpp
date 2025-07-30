#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool comp(Job a, Job b)
{
	if(a.profit > b.profit)
		return true;
	return false;
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
	sort(arr,arr+n,comp); // sorted based in max profit
	vector<int> vis(n+1,-1);
	int cnt = 0;
	int maxProfit = 0;
	for(int i=0; i<n; i++)
	{
		int day = arr[i].dead;
		// Can Run more max N times -> can be done by DSU (Graph) -> O(1)
		while(vis[day] != -1 && day > 0) // check if we can do this at its last day, if not then check for a day before
		{
			day--;
		}
		if(day > 0)
		{
			vis[day] = arr[i].id;
			maxProfit += arr[i].profit;
			cnt++;
		}
	}
	return {cnt, maxProfit};
} 

int main()
{
	
	return 0;
}

// Time Complexity - O(N^2 + NLogN)
// Space Complexity - O(N)