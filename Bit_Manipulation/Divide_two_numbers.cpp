#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int divide(int divid, int div) 
{
    long long dividend = divid;
    long long divisor = div;
    if(dividend==INT_MIN && divisor==-1) return INT_MAX;
    if(dividend==INT_MIN && divisor==1) return INT_MIN;
    int a = 0, b = 0;
    if(divisor < 0) 
    {
        divisor = -1*divisor;
        a = 1;
    }
    if(dividend < 0)
    {
        dividend = -1*dividend;
        b = 1;
    }
    
    long long ans = 0;
    while(dividend >= divisor)
    {
        int cnt = 0;    
        while(dividend >= (divisor << (cnt+1))) // d*2^cnt+1 -> till where d it can divide
            cnt++;
        dividend = dividend - (divisor << cnt); // reducing dividend according to where power of 2 divides
        ans += (divisor << cnt); // adding the power of two into variable
    }

    ans = ans/divisor;

    if(a^b) return (int)(-1*ans);
    else return (int)ans;
}

int main()
{
	int ans = divide(22,3);
	cout<<ans<<endl
	return 0;
}