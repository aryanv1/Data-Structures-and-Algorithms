#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time - O(2*N), Space - O(2*N)
bool checkValidString(string s) {
	int n = s.size();
	stack<int> s1,s2;
	// put '(' in s1 and if ')' encounters, popout '('
	// if '*' comes then push it in s2 to check whenever there is imbalance in brackets
	for(int i=0; i<n; i++)
	{
		if(s[i] == '(')
			s1.push(i);
		else if(s[i] == ')')
		{
			if(s1.empty())
			{
				if(s2.empty())
					return false;
				else s2.pop();
			}
			else
				s1.pop();
		}
		else if(s[i] == '*')
			s2.push(i);
	}
	while(!s1.empty())
	{
		if(s2.empty() && !s1.empty())
			return false;
		else if(s1.top() <= s2.top())
		{
			s1.pop();
			s2.pop();
		}
		else
			return false;
	}
	return true;
}

// Optimal approach -> Time - O(N), Space - O(1)
bool checkValidString(string s) 
{
	int n = s.size();
	int mini = 0;
	int maxi = 0;
	for(int i=0; i<n; i++)
	{
		if(s[i] == '(')
		{
			mini++;
			maxi++;
		}
		else if(s[i] == ')')
		{
			mini--;
			maxi--;
		}
		else
		{
			mini--;
			maxi++;
		}

		if(maxi < 0) return false;
		if(mini < 0) mini = 0;
	}
	return mini == 0;
}
// Here we have maintained a range 
// for simple parenthesis checker we do '('->+1, ')'->-1 and at the end if it is zero then true or in between if it goes <0 then false
// In this same thing is done but in range just for * which goes from -1 to 1, we subtract from mini and add in maxi
//when mini goes < 0 then it borrows 1 from maxi and if maxi goes < 0 then its not possible

int main()
{
	
	return 0;
}