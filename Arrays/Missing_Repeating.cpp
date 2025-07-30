#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute - traverse from 1toN and arr to find elements - O(n*n)\
// Better - Using Hashing - O(2*n) and O(n) space 
// Optimal - O(n)
vector<int> findTwoElement(vector<int>& arr) {
    // x -> repaeating number
    // y -> missing number
    long long n = arr.size();
    long long s1 = 0,s2 = 0;
    long long s1n = (n * (n+1))/2;
    long long s2n = (n * (n+1) * (2*n+1))/6;
    for(int i=0; i<n; i++)
    {
        s1 += arr[i];
        s2 += (long long)arr[i]*(long long)arr[i];
    }
    int val1 = s1 - s1n; // x - y
    int val2 = s2 - s2n; // x^2 - y^2 = (x-y)*(x+y)
    
    val2 = val2/val1; // x + y
    
    int x =  (val1 + val2)/2;
    int y = x - val1;
    
    return {x,y};
}

// Another Optimal Solution - O(3*N)
vector<int> XORSolution(vector<int> & arr) {
	int n = arr.size();
	int xr = 0;
	for(int i=0; i<n; i++)
	{
		xr = xr ^ arr[i];
		xr = xr ^ (i+1);
	}
	// Find the bit number where both numbers are different
	// This bitNo can be found using: (xr & ~(xr-1))
	int bitNo = 0;
	while(1)
	{
		if((xr & (1 << bitNo) == 1)
			break;
		bitNo++;
	}
	// Create wo buckets one of zero and other of One
	// Here in one bucket we will have missing number and in other repeating
	int zero = 0, one = 0;
	for(int i=0; i<n; i++)
	{
		if((arr[i] & (1 << bitNo)) == 0)
			zero = zero ^ arr[i];
		else
			one = one ^ arr[i];
	}

	for(int i=1; i<=n; i++)
	{
		if((arr[i] & (1 << bitNo)) == 0)
			zero = zero ^ i;
		else
			one = one ^ i;
	}

	// To confirm which one is repeating 
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i] == one)
			cnt++;
	}
	if(cnt == 1)
		return {zero,one};
	else
		return {one,zero};
}

int main()
{
	
	return 0;
}