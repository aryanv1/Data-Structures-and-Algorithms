#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute solution can be using stack - add elements into stack while keeping in mind the spcaes and pop out, it will be in reverse order - O(N), O(N)
// Optimal - O(N), O(1)
string reverseWords(string s) 
{
	int n = s.size();
	int left = 0, right = 0;
	int i=0;
	while(i < n)
	{
		while(i<n && s[i] == ' ')
			i++;
		if(i == n)
			break;
		while(i<n && s[i] != ' ')
		{
			s[right++] = s[i++];
		}
		s[right] = ' ';
		reverse(s.begin()+left,s.begin()+right);
		right++;
		left = right;
	}
	s.resize(right-1);
	reverse(s.begin(),s.end());
	return s;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(1)

// Keep right at beginning and i after spaces and copy each char at front while moing forward and after one word gets completed maintain space