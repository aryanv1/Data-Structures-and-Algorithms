#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Here we have to get the floor value so for brute force we can linearly traverse and check if i*i is <= given number or not
long long int floorSqrt(long long int x) 
{
    // Your code goes here 
    long long int l = 1;
    long long int h = x;
    long long int mid;
    long long int ans;
    while(l <= h)
    {
        mid = (l + h)/2;
        if(mid * mid <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        h = mid - 1;
    }
    return ans;
}

int main()
{
	ll x;
	cin>>x;
	ll ans = floorSqrt(x);
	cout<<ans<<endl;
	return 0;
}