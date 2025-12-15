#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity - O(K * 4 * α(N*M))  where K = no. of operators
// Space Complexity - O(N*M) for DSU and O(N*M) for matrix
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    // code here
    vector<vector<int>> mat(n, vector<int>(m, 0));
    int k = operators.size();
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int cnt = 0;
    vector<int> ans;
    Disjoint_Set ds(n * m);
    for (int i = 0; i < k; i++)
    {
        int x = operators[i][0];
        int y = operators[i][1];
        if (mat[x][y] == 1)
        {
            ans.push_back(cnt);
            continue;
        }
        mat[x][y] = 1;
        int nodeNum = x * m + y; // row*colSize + col
        cnt++;
        for (int j = 0; j < 4; j++)
        {
            int newX = x + dr[j];
            int newY = y + dc[j];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY])
            {
                int newNodeNum = newX * m + newY;
                int ultParNode = ds.findUPar(nodeNum);
                int ultParNewNode = ds.findUPar(newNodeNum);
                if (ultParNode != ultParNewNode)
                {
                    ds.UnionBySize(ultParNode, ultParNewNode);
                    cnt--;
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{

    return 0;
}