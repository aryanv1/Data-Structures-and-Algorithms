#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Find out the minimum and swap it with first non sorted index starting from 0
// Time Complexity - O(N^2), Space Complexity - O(1)
void Selection(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int ind = i;
		for(int j=i; j<n; j++)		{
			if(arr[j] < arr[ind])
			{
				ind = j;
			}
		}
		swap(arr[i],arr[ind]);
	}
}

int main()
{
	
	return 0;
}