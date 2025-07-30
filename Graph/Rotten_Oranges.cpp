#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int orangesRotting(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // {{r,c},t}
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];
    int c = 0;
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 2)
            {
                cnt++;
                vis[i][j] = 2;
                q.push({{i,j},0});
            }
            else
            vis[i][j] = 0;
            if(grid[i][j] == 2 || grid[i][j] == 1)
            c++;
        }
    }
    int tm = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;
        for(int i=0; i<4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            // tm = max(tm,time);
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                cnt++;
                vis[nrow][ncol] = 2;
                q.push({{nrow,ncol},time+1});
                tm = max(tm,time+1);
            }
        }
        q.pop();
    }
    if(cnt != c) return -1;
    return tm;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> grid;
	for(int i=0; i<n; i++)
	{
		vector<int> temp;
		for(int j=0; j<m; j++)
		{
			int m;
			cin>>m;
			temp.push_back(m);
		}
		grid.push_back(temp);
	}
	int k = orangesRotting(grid);
	cout<<k<<endl;
	return 0;
}
//Time Complexity - O(n*m)
//Space Complexity - O(n*m)
/*Input
0 1 2
0 1 2
2 1 1
*/