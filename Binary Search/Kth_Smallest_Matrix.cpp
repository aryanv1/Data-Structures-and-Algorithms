#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time Complexity: O(n log(max-min))
// Space Complexity: O(1)
// Matrix is row-wise and column-wise sorted -> We need to find kth smallest element
int kthSmallest(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // Count how many numbers are <= mid
        int count = countLessEqual(mat, mid);

        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int countLessEqual(vector<vector<int>> &mat, int mid)
{
    int count = 0;
    int n = mat.size();
    int row = n - 1; // Start from bottom-left
    int col = 0;

    while (row >= 0 && col < n)
    {
        if (mat[row][col] <= mid)
        {
            // Since columns are sorted, if mat[row][col] <= mid,
            // then all elements above it in this column are also <= mid.
            count += (row + 1);
            col++;
        }
        else
        {
            // If the element is too large, move up to a smaller value
            row--;
        }
    }
    return count;
}

int main()
{

    return 0;
}