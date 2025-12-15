#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void shortest_distance(vector<vector<int>> &matrix)
{
    // Code here
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // To check negative cycle just iterate over node i to i, i.e diagonal
    // If its negative then there is a negative cycle
    // for(int i=0; i<n; i++)
    // {
    // 	if(matrix[i][i] < 0)
    // 		//negative cycle
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

int main()
{
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1));
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    shortest_distance(matrix);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity - O(V^3)
//  Space Complexity - O(V^2) Considering we are using the given matrix
//  Multi Source shortest path

// We can use Dijkstra's Algo if there is no negative weight cycle
// Becuase Dijkstra's Algo will cause TLE in that case.
// Else it is more efficient than Floyd Warshall