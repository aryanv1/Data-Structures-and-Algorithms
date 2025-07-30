#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Optimal -> Time - O(N!*N) and Space - O(N)
void solve(int col, vector<vector<string>> &ans, vector<string> &board,vector<int> &LeftRow, vector<int> &UpperDiag, vector<int> &LowerDiag, int n)
{
	if(col == n)
	{
		ans.push_back(board);
		return ;
	}
	for (int row = 0; row < n; ++row)
	{
		if(LeftRow[row] == 0 && LowerDiag[col + row] == 0 && UpperDiag[n-1+col-row] == 0)
		{
			board[row][col] = 'Q';
			LeftRow[row] = 1;
			LowerDiag[col + row] = 1;
			UpperDiag[n-1+col-row] = 1;
			solve(col+1,ans,board,LeftRow,UpperDiag,LowerDiag,n);
			board[row][col] = '.';
			LeftRow[row] = 0;
			LowerDiag[col + row] = 0;
			UpperDiag[n-1+col-row] = 0;
		}
	}
}

int main()
{
	int n = 5;
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n,'.');
	for(int i=0; i<n; i++)
		board[i] = s;
	vector<int> LeftRow(n,0); // maintaining *columns in which every queen is placed
	vector<int> UpperDiag(2*n-1,0); //total size of 2n-1 -> row+col in these diagonals will be same 
	vector<int> LowerDiag(2*n-1,0); //total size of 2n-1 -> (n-1)+(col-row)in these diagonals  will be same
	solve(0,ans,board,LeftRow,UpperDiag,LowerDiag,n);
	for(int i=0; i<ans.size(); i++)
	{
		cout << "Arrangement " << i + 1 << "\n";
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout<<ans[i][j]<<endl;
		}
		cout<<endl;
	}
	return 0;
}

// Brute -> Time - O(N!*N) and Space -O(N*N)
class Solution {
public:
    vector<vector<string>> ans;
    bool check(int i, int j, vector<string> &res)
    {
        int col1 = j;
        while(col1 >= 0)
        {
            if(res[i][col1] == 'Q')
                return false;
            col1--;
        }
        int col2 = j;
        int row2 = i;
        while(col2>=0 && row2>=0)
        {
            if(res[row2][col2] == 'Q')
                return false;
            row2--;
            col2--;
        }
        int col3 = j;
        int row3 = i;
        while(col3>=0 && row3<res.size())
        {
            if(res[row3][col3] == 'Q')
                return false;
            row3++;
            col3--;
        }
        return true;
    }
    void solve(int col, int n, vector<string> &res)
    {
        if(col == n)
        {
            ans.push_back(res);
            return ;
        }
        for(int i=0; i<n; i++)
        {
            if(check(i,col,res) == true)
            {
                res[i][col] = 'Q';
                solve(col+1,n,res);
                res[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n,string(n,'.'));
        solve(0,n,s);
        return ans;
    }
};