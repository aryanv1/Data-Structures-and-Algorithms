#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// Brute -  Traverse through matri and for each element check in four directions - O(4*n*m)
// Better - Just find thr maximum element in the matircc and that will be the answer - O(n*m)
// Optimal - O(nlogm)
// Intuition - Find maximum element in th column which we figured in mid and then in that column, find maximum element
// Up and below will be definitely smaller that it and if any one of left or right is greater then go to that side in BS
// It is because on that side we will definitely find greater element since the compared element(due to which we move on that side) was already greater than whole previous column
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        int ind = -1;
        int maxi = -1;
        //finding peak element in col = mid
        for(int i=0; i<n; i++)
        {
            if(mat[i][mid] > maxi)
            {
                maxi = mat[i][mid];
                ind = i;
            }
        }
        int left = mid-1>0 ? mat[ind][mid-1] : -1;
        int right = mid+1<m ? mat[ind][mid+1] : -1;
        if(left > mat[ind][mid])
        high = mid-1;
        else if(right > mat[ind][mid])
        low = mid+1;
        else return {ind,mid};
    }
    return {-1,-1};
}

int main()
{
	
	return 0;
}