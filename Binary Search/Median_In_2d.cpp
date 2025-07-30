#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute - Put all elements in an array then sort it and find median
// Optimal - if number of elements to less than equal to chosen element is equal to (n*m)/2 then we have to move to right because for median number of elements less than equal to it will always be greater than (n*m)/2
// Find number of elements less than or equal to using upper_bound
// Time Complexity - O(mlogn * log(max-min))
int upperBound(vector<int> &arr, int x, int n) { // O(logn)
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) { // O(mlogn)
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) { // log(max-min)
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main()
{
	
	return 0;
}