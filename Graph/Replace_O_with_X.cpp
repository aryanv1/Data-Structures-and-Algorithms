#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve_dfs(int i,int j,vector<vector<char>>board,vector<vector<int>>&vis)
{
    int n = board.size();
    int m = board[0].size();
    vis[i][j] = 1;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    for(int k=0; k<4; k++)
    {
        int nrow = i + drow[k];
        int ncol = j + dcol[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
        && board[nrow][ncol] == 'O' && !vis[nrow][ncol])
        {
            vis[nrow][ncol] = 1;
            solve_dfs(nrow,ncol,board,vis);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    //traverse top and bottom rows
    for(int j=0; j<m; j++)
    {
        if(!vis[0][j] && board[0][j] == 'O')
        {
            solve_dfs(0,j,board,vis);
        }
        if(!vis[n-1][j] && board[n-1][j] == 'O')
        {
            solve_dfs(n-1,j,board,vis);
        }
    }
    //traverse leftmost and rightmost columns
    for(int i=0; i<n; i++)
    {
        if(!vis[i][0] && board[i][0] == 'O')
        {
            solve_dfs(i,0,board,vis);
        }
        if(!vis[i][m-1] && board[i][m-1] == 'O')
        {
            solve_dfs(i,m-1,board,vis);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0 ; j<m; j++)
        {
            if(vis[i][j] == 0)
            board[i][j] = 'X';
            else board[i][j] = 'O';
        }
    }
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>> board;
	for(int i=0; i<n; i++)
	{
		vector<char> temp;
		for (int j = 0; j < m; ++j)
		{
			int m;
			cin>>m;
			temp.push_back(m);
		}
		board.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
//Time complexity - O(n*m)
//Space complexity - O(n*m)
/*Input
6 6
X X X O X X
X X O O O X
X X X X X X
X X O O X X
X X O O X X
X X X X X X
*/