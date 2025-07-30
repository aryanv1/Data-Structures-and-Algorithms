#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(2*N*N)
void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
            	// Separately marking for column zero
                if(j == 0 && matrix[i][0] == 0)
                    col = 0;
                else if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(matrix[0][0] == 0)
        {
            for(int j=0; j<m; j++)
                matrix[0][j] = 0;
        }
        if(col == 0)
        {
            for(int i=0; i<n; i++)
                matrix[i][0] = 0;
        }
    }

int main()
{
	
	return 0;
}