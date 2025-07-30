#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute -> 3 loops -> innermost to traverse and calculate xor
// Better -> Two loops -> calculate xor in second loop
// Optimal - O()
long subarrayXor(vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int,int> m;
    int xr = 0;
    int cnt = 0;
    m[0] = 1;
    for(int i=0; i<n; i++)
    {
        xr = xr ^ arr[i];
        cnt += m[xr^k];
        m[xr]++;
    }
    return cnt;
}

int main()
{
	
	return 0;
}