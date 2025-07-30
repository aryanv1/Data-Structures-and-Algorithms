#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j] == 1)
                    {
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int ii = q.front().first;
            int jj = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nrow = ii + drow[i];
                int ncol = jj + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                cnt++;
            }
        }
        return cnt;
    }

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> board;
	for(int i=0; i<n; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m; ++j)
		{
			int m;
			cin>>m;
			temp.push_back(m);
		}
		board.push_back(temp);
	}
	int k = numberOfEnclaves(board);
	cout<<k<<endl;
	return 0;
}
/*Input
4 4
0 1 1 0
0 0 1 0
0 0 1 0
0 0 0 0
*/