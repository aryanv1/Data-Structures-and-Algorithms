#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time - O(4^(n*m)), Space - O(n*m) // recursion stack
void solve(int i, int j, int n, int m, vector<vector<int>> &maze, vector<string> &ans, string &s)
{
    if(i == n-1 && j == m-1)
    {
        ans.push_back(s);
        return ;
    }
    if(i<0 || i>=n || j<0 || j>=m)
        return ;
    if(i+1<n && maze[i+1][j] == 1)
    {
        s += 'D';
        maze[i][j] = 0;
        solve(i+1,j,n,m,maze,ans,s);
        s.pop_back();
        maze[i][j] = 1;
    }
    if(j-1>=0 && maze[i][j-1] == 1)
    {
        s += 'L';
        maze[i][j] = 0;
        solve(i,j-1,n,m,maze,ans,s);
        s.pop_back();
        maze[i][j] = 1;
    }
    if(j+1<m && maze[i][j+1] == 1)
    {
        s += 'R';
        maze[i][j] = 0;
        solve(i,j+1,n,m,maze,ans,s);
        s.pop_back();
        maze[i][j] = 1;
    }
    if(i-1>=0 && maze[i-1][j] == 1)
    {
        s += 'U';
        maze[i][j] = 0;
        solve(i-1,j,n,m,maze,ans,s);
        s.pop_back();
        maze[i][j] = 1;
    }
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    // code here
    int n = maze.size();
    int m = maze[0].size();
    if(maze[0][0] == 0)
        return {};
    vector<string> ans;
    string s;
    solve(0,0,n,m,maze,ans,s);
    return ans;
}

int main()
{
	vector<vector<int>> v = {{1, 0, 0, 0},
         					 {1, 1, 0, 1}, 
         					 {1, 1, 0, 0},
         					 {0, 1, 1, 1}};
    vector<string> ans;
    string out = "";
    vector<vector<int>> visited = v;
    for(int i=0; i<v.size(); i++)
    {
    	for(int j=0; j<v[0].size(); j++)
    	{
    		visited[i][j] = 0;
    	}
    }
    solve(v,0,0,ans,out,visited);
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
    	cout<<ans[i]<<endl;
	return 0;
}