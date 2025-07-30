#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time - O(NlogN)
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    sort(strs.begin(),strs.end());
    string a = strs[0];
    string b = strs[n-1];
    string ans = "";
    for(int i=0; i<min(a.size(),b.size()); i++)
    {
        if(a[i] == b[i])
            ans += a[i];
        else
            break;
    }
    return ans;
}

int main()
{
	
	return 0;
}