#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int max_area(vector<int> &heights, int n)
{
	stack<int> st;
	int maxi = 0;
	for(int i=0; i<=n; i++)
	{
		while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
		{
			int h = heights[st.top()];
			st.pop();
			int width;
			if(st.empty())
				width = i;
			else
				width = i-st.top()-1;
			maxi = max(maxi,h*width);
		}
		st.push(i);
	}
	return maxi;
}
int maximalRectangle(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	vector<int> h(m,0);
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(matrix[i][j] == 1)
				h[j]++;
			else
				h[j] = 0;
		}
		int area = max_area(h,m);
		ans = max(ans,area);
	}
	return ans;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> matrix = {{0,1,1,0},
         						  {1,1,1,1},
         						  {1,1,1,1},
         						  {1,1,0,0}};
	int ans = maximalRectangle(matrix);
	cout<<ans<<endl;
	return 0;
}

// Time Complexity - O(N*N)
// Space Complexity - O(N)