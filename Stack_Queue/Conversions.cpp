#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Priority Order -> '^' > '*' = '/' > '+' = '-' > any other

int priority(char c)
{
	if(c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// Push operand elements into ans and opening bracket to stack
// For closing Bracket, push into ans from stack till opening bracket comes
// Always keep operator with highest priority at top of stack
string Infix_Postfix(string s)
{
	int n = s.size();
	stack<char> st;
	string ans = "";
	for(int i=0; i<n; i++)
	{
		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
			(s[i] >= '0' && s[i] <= '9'))
		{
			ans += s[i];
		}
		else if(s[i] == '(')
		{
			st.push('(');
		}
		else if(s[i] == ')')
		{
			while(!st.empty() && st.top() != '(')
			{
				ans += st.top();
				st.pop();
			}
			st.pop();
		}
		else 
		{
			while(!st.empty() && priority(st.top()) >= priority(s[i]))
			{
				ans += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	return ans;
}


// Reverse the given string and change brackets i.e, '(' -> ')' and ')' -> '('
// Do Infix to postfix with controlled conditions
// Conditions -> if operator is '^' then do as it is
// If operator is any other, then donot pop if we get operators with same prioirty
// But pop if operator with lesser prioirty comes
// return the string after reversing
string Infix_Prefix(string s)
{
	int n = s.size();
	stack<char> st;
	string ans = "";
	reverse(s.begin(),s.end());
	for(int i=0; i<n; i++)
	{
		if(s[i] == '(')
			s[i] = ')';
		else if(s[i] == ')')
			s[i] = '(';
	}
	for(int i=0; i<n; i++)
	{
		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
			(s[i] >= '0' && s[i] <= '9'))
		{
			ans += s[i];
		}
		else if(s[i] == '(')
		{
			st.push('(');
		}
		else if(s[i] == ')')
		{
			while(!st.empty() && st.top() != '(')
			{
				ans += st.top();
				st.pop();
			}
			st.pop();
		}
		else 
		{
			if(s[i] == '^')
			{
				while(!st.empty() && s[i] == st.top()) // same '^' is there
				{
					ans += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else
			{
				while(!st.empty() && priority(s[i]) < priority(st.top()))
				{
					ans += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
	}
	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(),ans.end());
	return ans;
}


// Whenever a operand comes just push into stack
// in case of operator, take top two elements from stack and put this operand in between them and push this combined string into stack
// Atlast only one string will remain in stack that will be our answer
string Postfix_Infix(string s)
{
	int n = s.size();
	stack<string> st;
	for(int i=0; i<n; i++)
	{
		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
			(s[i] >= '0' && s[i] <= '9'))
		{
			string t;
		    t += s[i];
			st.push(t);
		}
		else
		{
			string t1 = st.top();
			st.pop();
			string t2 = st.top();
			st.pop();
			st.push('(' + t2 + s[i] + t1 + ')');
		}
	}
	return st.top();
}

// Same as postfix to infix but with slight change
// Traverse array from back and take the top operand first and then second one
string Prefix_Infix(string s)
{
	int n = s.size();
	stack<string> st;
	for(int i=n-1; i>=0; i--)
	{
		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
			(s[i] >= '0' && s[i] <= '9'))
		{
			string t;
		    t += s[i];
			st.push(t);
		}
		else
		{
			string t1 = st.top();
			st.pop();
			string t2 = st.top();
			st.pop();
			st.push('(' + t1 + s[i] + t2 + ')'); // change in order
		}
	}
	return st.top();
}


// Same as in POstfix to infix just minor change
// put operator first and then second operand and then first or top operand
string Postfix_Prefix(string s)
{
	int n = s.size();
	stack<string> st;
	for(int i=0; i<n; i++)
	{
		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
			(s[i] >= '0' && s[i] <= '9'))
		{
			string t;
		    t += s[i];
			st.push(t);
		}
		else
		{
			string t1 = st.top();
			st.pop();
			string t2 = st.top();
			st.pop();
			st.push(s[i] + t2 + t1);
		}
	}
	return st.top();
}

// Same as above just change in order of operators and operands and traverse loop from back
string Prefix_Postfix(string s)
{
	int n = s.size();
	stack<string> st;
	for(int i=n-1; i>=0; i--)
	{
		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
			(s[i] >= '0' && s[i] <= '9'))
		{
			string t;
		    t += s[i];
			st.push(t);
		}
		else
		{
			string t1 = st.top();
			st.pop();
			string t2 = st.top();
			st.pop();
			st.push(t1 + t2 + s[i]); // change in order
		}
	}
	return st.top();
}

int main()
{
	
	return 0;
}