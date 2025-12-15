#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Here we are making rows and columns as nodes
// And connecting row node to column node if stone is present at that position
// Column nodes are mapped after all row nodes to avoid collision i.e,
// if there are r rows and c columns then row nodes will be from 0 to r-1
// and column nodes will be from r to r+c-1
// Finally number of connected components will give number of stones
// Time Complexity - O(N*α(N)) , α is inverse Ackermann function
// Space Complexity - O(N) + O(r+c) -> for disjoint set and map

// Make sure that additonal Nodes for rows and columns are also generated
// while creating Disjoint Set which don't have any stones
// So we donot have to consider that while counting connected components
int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    int r, c;
    for (auto it : stones)
    {
        r = max(r, it[0]);
        c = max(c, it[1]);
    }
    // mapping columns after r rows
    unordered_map<int, int> m;
    Disjoint_Set ds(r + c + 1); // +1 for safety
    for (auto it : stones)
    {
        int nr = it[0];
        int nc = it[1] + r + 1;
        ds.UnionBySize(nr, nc);
        m[nr] = 1;
        m[nc] = 1;
    }
    int cnt = 0;
    for (auto it : m)
    {
        if (ds.findUPar(it.first) == it.first)
            cnt++;
    }
    return n - cnt;
}

int main()
{

    return 0;
}