#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> findPeakGrid(vector<vector<int>>& mat) 
{
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
	vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
	vector<int> ans = findPeakGrid(mat);
	cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}