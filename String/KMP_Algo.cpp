#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> search(string pat, string s)
{
	int n = s.size();
	int m = pat.size();
	vector<int> ans;
	vector<int> lps(m,0);
    // Time Complexity - O(M)
	for(int i=1; i<m; i++)
	{
		int j = lps[i-1];

		while(j>0 && pat[i] != pat[j])
			j = lps[j-1];

		if(pat[i] == pat[j])
			j++;

		lps[i] = j;
	}

	int i=0, j=0;
	while(i < n)
	{
		if(s[i] == pat[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
		if(j == m)
		{
			ans.push_back(i-m+1);
            j = lps[m-1]; // matches string again
        }
    }
    return ans;
}

int main()
{

	return 0;
}

// Time Complexity - O(N+M)
// Space Complexity - O(M)