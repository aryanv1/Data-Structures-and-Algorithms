#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long func(int b, int exp) {
    long long  ans = 1;
    long long base = b;
    while (exp > 0) {
        if (exp % 2) {
            ans = ans * base;
            exp--;
        }
        else {
            base = base * base;
            exp /= 2;
        }
    }
    return ans;
}
// Recursive approach
double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return n%2==0 ? myPow(x*x, n/2) : x*myPow(x, n-1);
    }

int main()
{
	
	return 0;
}