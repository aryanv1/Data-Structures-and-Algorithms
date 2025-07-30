#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int celebrity(vector<vector<int> >& mat, int n) 
{
	stack<int> st;
	for(int i=0; i<n; i++)
		st.push(i);

	while(st.size() > 1)
	{
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();
		if(mat[a][b] == 1)
			st.push(b);
		else
			st.push(a);
	}

	int celebrity = st.top();

	int zero = 0,one = 0;
	for(int i=0; i<n; i++)
	{
		if(mat[celebrity][i] == 0)
			zero++;
	}

	if(zero != n)
		return -1;

	for(int i=0; i<n; i++)
	{
		if(mat[i][celebrity] == 1)
			one++;
	}

	if(one != n-1)
		return -1;

	return celebrity;
}

int main()
{
	vector<vector<int>> mat = {{0,1,0},
					           {0,0,0}, 
					           {0,1,0}};
	int n = 3;
	int ans = celebrity(mat,n);
	cout<<ans<<endl;				    
	return 0;
}

// Time Complexity - O(n)
// Space Complexity - O(n)