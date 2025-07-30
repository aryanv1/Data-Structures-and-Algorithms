#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time - O(3N), Space - O(N)
int minCandy(int N, vector<int> &ratings) 
{
	vector<int> t(N,1);
	for(int i=1; i<N; i++)
	{
		if(ratings[i] > ratings[i-1])
		{
			t[i] = t[i-1] + 1;
		}
	}
	for(int i=N-2; i>=0; i--)
	{
		if(ratings[i] > ratings[i+1])
		{
			t[i] = max(t[i+1]+1,t[i]);
		}
	}
	int ans = 0;
	for(int i=0; i<N; i++)
	{
		ans = ans + t[i];
	}
	return ans;
}

// Time - O(N), Space - O(1)
int candy(vector<int>& ratings) {
	int n = ratings.size();
	int sum = 1;
	int i = 1; 
	while(i < n)
	{
		// add 1 if elements are same
		if(ratings[i] == ratings[i-1])
		{
			sum++;
			i++;
			continue;
		}
		// for increasing order just increment and add to sum by maintaining peak
		int peak = 1;
		while(i<n && ratings[i] > ratings[i-1])
		{
			peak++;
			sum += peak;
			i++;
		}
		// After reaching peak, go down by again starting from 1 
		int down = 1;
		while(i<n && ratings[i] < ratings[i-1])
		{
			sum += down; // this both are not same as in above loop
			down++; // this both are not same as in above loop
			i++;
		}
		// At last after coming down if down is greater that means peak value should be down+1 do add accordingly
		if(down > peak)
			sum += (down-peak);
	}
	return sum;
}

int main()
{
	
	return 0;
}