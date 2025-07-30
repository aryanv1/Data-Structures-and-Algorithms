#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int a,int b, vector<vector<int>>image,int drow[],int dcol[],
	vector<vector<int>> &vis, int n, int m, int color)
{
    for(int i=0; i<4; i++)
    {
        int nrow = a + drow[i];
        int ncol = b + dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
        && image[nrow][ncol] == image[a][b] && vis[nrow][ncol] != color)
        {
            vis[nrow][ncol] = color;
            dfs(nrow,ncol,image,drow,dcol,vis,n,m,color);
        }
    }
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> image;
	for(int i=0; i<n; i++)
	{
		vector<int> temp;
		for(int j=0; j<m; j++)
		{
			int m;
			cin>>m;
			temp.push_back(m);
		}
		image.push_back(temp);
	}
	int sr,sc;
	cin>>sr>>sc;
	int color;
	cin>>color;
	// --------------------------
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    vector<vector<int>> vis = image;
    vis[sr][sc] = color;
    dfs(sr,sc,image,drow,dcol,vis,n,m,color);
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		cout<<vis[i][j]<<" ";
    	}
    	cout<<endl;
    }
	return 0;
}
/*Input
3 3
1 1 1
1 1 0
1 0 1
1 1
2
*/