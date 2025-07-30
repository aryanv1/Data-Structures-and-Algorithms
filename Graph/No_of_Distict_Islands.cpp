#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
void dfs(int i, int j, int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>> &ds)
{
	vis[i][j] = 1;
	ds.push_back({i-x,j-y});
	for(int k=0; k<4; k++)
	{
		int ii = i + dr[k];
		int jj = j + dc[k];
		if(ii>=0 && ii<grid.size() && jj>=0 && jj<grid[0].size() && grid[ii][jj] == 1 && !vis[ii][jj])
		{
			dfs(ii,jj,x,y,grid,vis,ds);
		}
	}
}
int countDistinctIslands(vector<vector<int>>& grid) 
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> vis(n,vector<int>(m,0));
	set<vector<pair<int,int>>> s;
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(!vis[i][j] && grid[i][j] == 1)
			{
				vector<pair<int,int>> ds;
				dfs(i,j,i,j,grid,vis,ds);
				if(s.find(ds) == s.end())
				{
					s.insert(ds);
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main()
{
	
	return 0;
}

// Islands should not have same shape -> start base pointer of every island with (0,0) and put in vector of pairs, if we got same set of pairs then that island will be same