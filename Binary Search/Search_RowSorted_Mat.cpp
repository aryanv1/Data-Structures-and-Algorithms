#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute - Just traverse through matrix and find the target
// Better - Apply BS only if targte lies in that row - O(n+logm)
bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

// Optimal - O(log(n*m))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = m*n-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(matrix[mid/m][mid%m] == target)
                return true;
            else if(matrix[mid/m][mid%m] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }

int main()
{
	
	return 0;
}	