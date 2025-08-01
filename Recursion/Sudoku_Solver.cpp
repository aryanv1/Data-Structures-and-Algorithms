#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 9

// Time - O(9^(n*n))
bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for(int i=0; i<9; i++)
        {
            if(board[row][i] == c)
            return false;
            if(board[i][col] == c)
            return false;
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c)
            return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> & board)
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char k='1'; k<='9'; k++)
                    {
                        if(isValid(board,i,j,k))
                        {
                            board[i][j] = k;
                            if(solve(board))
                            return true;
                            else
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

int main()
{
	vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solveSudoku(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
	return 0;
}