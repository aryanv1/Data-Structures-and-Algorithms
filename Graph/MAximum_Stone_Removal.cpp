#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int removeStones(vector<vector<int>>& stones) 
{
	int n = stones.size();
	int r,c;
	for(auto it : stones)
	{
		r = max(r,it[0]);
		c = max(c,it[1]);
	}
    // mapping columns after r rows
    // treating rows as node and mapping every {i,j} to it
	unordered_map<int,int> m;
    Disjoint_Set ds(r+c+1); // +1 for safety
    for(auto it : stones)
    {
    	int nr = it[0];
    	int nc = it[1]+r+1;
    	ds.UnionBySize(nr,nc);
    	m[nr] = 1;
    	m[nc] = 1;
    }
    int cnt = 0;
    for(auto it : m)
    {
    	if(ds.findUPar(it.first) == it.first)
    		cnt++;
    }
    return n - cnt;
}

int main()
{
	int n = 6;
    vector<vector<int>> stones = {
        {0, 0}, {0, 2},
        {1, 3}, {3, 1},
        {3, 2}, {4, 3}
    };

    int ans = maxRemove(stones, n);
    cout<<ans<<endl;
	return 0;
}