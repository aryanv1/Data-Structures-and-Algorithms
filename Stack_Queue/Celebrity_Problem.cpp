#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute Force approach
// Time Complexity - O(n^2)
// Space Complexity - O(n)
int celebrity(vector<vector<int>> &mat)
{
	// code here
	int n = mat.size();
	vector<int> row(n, 0);
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += mat[i][j];
		}
		row[i] = sum;
	}
	vector<int> col(n, 0);
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += mat[j][i];
		}
		col[i] = sum;
	}
	for (int i = 0; i < n; i++)
	{
		if (row[i] == 1 && col[i] == n)
		{
			return i;
		}
	}
	return -1;
}

// Better approach using stack
// Time Complexity - O(n)
// Space Complexity - O(n)
int celebrity(vector<vector<int>> &mat, int n)
{
	stack<int> st;
	for (int i = 0; i < n; i++)
		st.push(i);

	while (st.size() > 1)
	{
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();
		if (mat[a][b] == 1)
			st.push(b);
		else
			st.push(a);
	}

	int celebrity = st.top();

	int zero = 0, one = 0;
	for (int i = 0; i < n; i++)
	{
		if (mat[celebrity][i] == 0)
			zero++;
	}

	if (zero != n)
		return -1;

	for (int i = 0; i < n; i++)
	{
		if (mat[i][celebrity] == 1)
			one++;
	}

	if (one != n - 1)
		return -1;

	return celebrity;
}

// Optimal approach using two pointer
// Time Complexity - O(n)
// Space Complexity - O(1)
int celebrity(vector<vector<int>> &mat)
{
	// code here
	int n = mat.size();
	int top = 0, bottom = n - 1;
	while (top < bottom)
	{
		if (mat[top][bottom] == 1) // top know bottom
			top++;
		else if (mat[bottom][top] == 1) // bottom knows top
			bottom--;
		else // both doesn't know each other
		{
			top++;
			bottom--;
		}
	}
	if (top > bottom)
		return -1;
	for (int i = 0; i < n; i++)
	{
		if (i == top)
			continue; // celebrity know himself is 0
		if (mat[top][i] != 0 || mat[i][top] != 1)
			return -1;
	}
	return top;
}

int main()
{
	vector<vector<int>> mat = {{0, 1, 0},
							   {0, 0, 0},
							   {0, 1, 0}};
	int n = 3;
	int ans = celebrity(mat, n);
	cout << ans << endl;
	return 0;
}