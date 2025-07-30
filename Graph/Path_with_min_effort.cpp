#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int MinimumEffort(vector<vector<int>>& h) 
{
    // Code here
    int n = h.size();
    int m = h[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> ans(n,vector<int>(m,1e9));
    ans[0][0] = 0;
    pq.push({0,{0,0}});
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(!pq.empty())
    {
        pair<int,pair<int,int>> p = pq.top();
        int dis = p.first;
        int x = p.second.first;
        int y = p.second.second;
        pq.pop();
        if(x == n-1 && y == m-1) return dis;
        for(int i=0; i<4; i++)
        {
            int xx = x + dr[i];
            int yy = y + dc[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m)
            {
                int diff = max(abs(h[x][y]-h[xx][yy]),dis); // maintain max diff in that particular path
                if(diff < ans[xx][yy]) // replaces height diff. of previous path(greater diff) with this if it is less 
                {
                    ans[xx][yy] = diff;
                    pq.push({diff,{xx,yy}});
                }
            }
        }
    }
    return 0;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> v;
	for(int i=0; i<n; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m; ++j)
		{		
			int x;
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}
	int ans = MinimumEffort(v);
	cout<<v<<endl;
	return 0;
}
/*
1,2,2
3,8,2
5,3,5
ans = 2
*/