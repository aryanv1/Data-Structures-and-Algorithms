#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int XOR_1toN(int n)
{
	if(n % 4 == 1) return 1;
	else if(n % 4 == 2) return n+1;
	else if(n % 4 == 3) return 0;
	else return n;
}
int findXOR(int l, int r) {
        // complete the function here
	int xor_till_lminus1 = XOR_1toN(l-1);
	int xor_till_r = XOR_1toN(r);
	return xor_till_r ^ xor_till_lminus1;
}

int main()
{
	int ans = findXOR(4,9);
	cout<<ans<<endl;
	return 0;
}

// Time Commplexity - O(1)
// Space Complexity - O(1)

/* 1 to N(10)
1 -> 1 
2 -> 3
3 -> 0
4 -> 4
5 -> 1
6 -> 7
7 -> 0
8 -> 8
9 -> 1
10 -> 11

Pattern in 1 to N function
*/
// for l to r, simply find xor till l-1 and till r and take xor of both 