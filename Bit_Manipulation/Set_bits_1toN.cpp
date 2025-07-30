#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int count_power_of_2(int n)
{
	int i = 0;
	while((1<<i) <= n)
		i++;
	return i-1;
}
int countSetBits(int n)
{
	if(n == 0)
		return 0;
	int x = count_power_of_2(n);
    int set_bits_upto_2powX = x * (1 << (x-1)); // (2^(x-1)) * x
    int remaining_set_bits = n - (1 << x) + 1;
    int remaining = n - (1 << x); // not +1 beacuse rest will start from 0
    int ans = set_bits_upto_2powX + remaining_set_bits + countSetBits(remaining);
    return ans;
}

int main()
{
	int n = 5;
	int ans = countSetBits(n);
	cout<<ans<<endl;
	return 0;
}

/*  0001 -> 1
	0010 -> 2
	0011 -> 3
	0100 -> 4 
	0101 -> 5 
	0110 -> 6
	0111 -> 7 -> till here, no. of set bits will be 2^3-1 * 3
	1000 -> 8 	|
	1001 -> 9	|	
	1010 -> 10  | -> these are having first bit set = n-2^x+1
	1011 -> 11 	| -> for remaing 3 bits we can again call the function to solve the same way
	1100 -> 12 	|
	1101 -> 13  | => nearest power of 2 is 2^3 => x=2
*/