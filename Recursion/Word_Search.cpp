#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool  solve(vector<vector<char>> &board, string word,int n, int m, int k,int i,int j,int l)
{
	if(l == k) 
		return 1;

	if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[l])
		return 0;

	char ch = board[i][j];
	board[i][j] = '*';
	bool ans1 = solve(board,word,n,m,k,i+1,j,l+1);
	bool ans2 = solve(board,word,n,m,k,i,j+1,l+1);
	bool ans3 = solve(board,word,n,m,k,i-1,j,l+1);
	bool ans4 = solve(board,word,n,m,k,i,j-1,l+1);
	board[i][j] = ch;

	return ans1 || ans2 || ans3 || ans4;
}
bool exist(vector<vector<char>>& board, string word) {
	int n = board.size();
	int m = board[0].size();
	int k = word.size();
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(solve(board,word,n,m,k,i,j,0))
				return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> board = {{'A','B','C','E'},
								  {'S','F','C','S'},
								  {'A','D','E','E'}};
	string word = "ABCCED";
	bool ans = exist(board,word);
	cout<<ans<<endl;
	return 0;
}