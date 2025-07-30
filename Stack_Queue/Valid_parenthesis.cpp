#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(string s) 
{
	stack<char> st;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);
		else
		{
			if(st.empty()) return false;
			else if(s[i] == ')' && st.top() != '(')
				return false;
			else if(s[i] == '}' && st.top() != '{')
				return false;
			else if(s[i] == ']' && st.top() != '[')
				return false;
			else
				st.pop();
		}
	}
	if(!st.empty()) return false;
	return true;
}

int main()
{
	string s;
	cin>> s;
	bool ans = isValid(s);
	cout<<ans<<endl;
	return 0;
}