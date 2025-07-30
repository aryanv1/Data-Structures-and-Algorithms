#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Inplace rotation
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    // Step 1: Transpose the Matrix
    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<i; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // Reverse every row
    for(int i=0; i<n; i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

// Brute force -> Create a separate matrix and store answer in it
vector<vector<int>> rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        rotated[j][n - i - 1] = matrix[i][j]; // Observation
	    }
    }
    return rotated;
}

int main()
{
	
	return 0;
}