#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string removeOuterParentheses(string s) 
{
	int n = s.size();
	int i=0,j=1;
	int cnt = 1;
	while(j<n)
	{
		if(s[j] == '(')
			cnt++;
		else
			cnt--;

		if(cnt == 0)
		{
			s[i] = '*';
			s[j] = '*';
			i = j+1;
			j = i;
			cnt = 1;
		}
		j++;
	}
	string ans = "";
	for(int i=0; i<n; i++)
	{
		if(s[i] != '*')
			ans.push_back(s[i]);
	}
	return ans;
}

int main()
{
	
	return 0;
}

// Whenever count becomes zero make i and j star which represents outmost prenthesis 