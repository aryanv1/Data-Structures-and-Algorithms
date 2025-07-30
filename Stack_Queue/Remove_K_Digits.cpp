#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string removeZero(string &str) 
{ 
    // Count leading zeros 
	int i = 0; 
	while (str[i] == '0') 
		i++; 

	str.erase(0, i); 

	return str; 
}
string removeKdigits(string num, int k) 
{
	int n = num.size();
	stack<char> st;
	st.push(num[0]);
	for(int i=1; i<n; i++)
	{
		while(!st.empty() && st.top() > num[i] && k)
		{
			st.pop();
			k--;
		}
		st.push(num[i]);
	}
	while(k-- && !st.empty())
		st.pop();

	string ans;
	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(),ans.end());
	string res = removeZero(ans);
	if(res == "") return "0";
	return res;
}

int main()
{
	int k;
	cin>>k;
	string s;
	cin>>s;
	string ans = removeKdigits(s,k);
	cout<<ans<<endl;
	return 0;
}

// k=3  "1432219"

// Time Complexity - O(N)
// Space Complexity - O(N)