#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int braces(string A) {
	int n = A.size();
	stack<char> st;
	for(int i=0; i<n; i++)
	{
		if(A[i] == '*' || A[i] == '/' || A[i] == '+' || A[i] == '-' || A[i] == '(')
			st.push(A[i]);

		if(A[i] == ')')
		{
			if(st.top() == '(')
				return 1;
			else
			{
				while(st.top() != '(')
					st.pop();

				st.pop();
			}
		}
	}
	return 0;
}

int main()
{
	
	return 0;
}

// ((a+b)) -> redundant
// ((a*b)+(c+d)) -> Not Redundant