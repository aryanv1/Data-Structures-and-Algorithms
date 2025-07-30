#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>>nearest(vector<vector<int>>grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 1)
            {
                vis[i][j] = 1;
                q.push({{i,j},0});
            }
        }
    }
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(!q.empty())
    {
        int ii = q.front().first.first;
        int jj = q.front().first.second;
        int k = q.front().second;
        ans[ii][jj] = k;
        for(int p=0; p<4; p++)
        {
            int ni = ii + dr[p];
            int nj = jj + dc[p];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj] == 1
            && !vis[ni][nj])
            {
                vis[ni][nj] = 1;
                q.push({{ni,nj},k+1});
            }
        }
        q.pop();
    }
    return ans;
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
			int a;
			cin>>a;
			temp.push_back(a);
		}
		grid.push_back(temp);
	}
	vector<vector<int>> ans = nearest(grid);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}