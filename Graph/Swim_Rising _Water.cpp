#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int swimInWater(vector<vector<int>>& grid) 
{
	int n = grid.size();
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;
	vector<vector<int>> vis(n,vector<int>(n,0));
	q.push({grid[0][0],{0,0}});
	vis[0][0] = 1;
	int dr[4] = {-1,0,1,0};
	int dc[4] = {0,1,0,-1};
	while(!q.empty())
	{
		int i = q.top().second.first;
		int j = q.top().second.second;
		int time = q.top().first;
		q.pop();

		if(i == n-1 && j == n-1)
			return time;

		for(int k=0; k<4; k++)
		{
			int newR = i + dr[k];
			int newC = j + dc[k];
			if(newR>=0 && newR<n && newC>=0 && newC<n && !vis[newR][newC])
			{
				if(grid[newR][newC] <= time)
				{
					q.push({time,{newR,newC}});
				}
				else
				{
					q.push({grid[newR][newC],{newR,newC}});
				}
				vis[newR][newC] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	
	return 0;
}