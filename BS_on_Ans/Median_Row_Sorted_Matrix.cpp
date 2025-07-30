#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<vector<int>> mat, int mid,int n,int m)
{
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		ans += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();  
	}
	return ans;
}
int median(vector<vector<int>> &mat, int n, int m)
{  
	int med = (n*m)/2;
	int low = INT_MAX, high = INT_MIN;
	for(int i=0; i<n; i++)
		low = min(low,mat[i][0]);
	for(int i=0; i<n; i++)
		high = max(high,mat[i][m-1]);

	while(low <= high)
	{
		int mid = (low+high)/2;
		int less_equal = solve(mat,mid,n,m);
		if(less_equal > med)
			high = mid-1;
		else
            low = mid+1; // equal to in low side because if there are equal elements then median will be towards high
    }
    return low;
}

int main()
{
	vector<vector<int>> arr = {{1,3,5},{2,6,9},{3,6,9}};
	int ans = median(arr,3,3);
	cout<<ans<<endl;
	return 0;
}