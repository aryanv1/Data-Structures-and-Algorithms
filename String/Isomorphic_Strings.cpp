#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isIsomorphic(string s, string t) {
	int n1 = s.size();
	int n2 = t.size();
	if(n1 != n2) return false;
	unordered_map<char,char> m1,m2;
	for(int i=0; i<n1; i++)
	{
		if(m1.find(s[i]) != m1.end())
		{
                if(m1[s[i]] != t[i]) // checking if char of s mapped to char of t is the same char present at index i in string t
                return false;
        }
        else if(m2.find(t[i]) != m2.end()) // if char at i in s is not in map1 but char at i in t is already in map2 then it should have already mapped so cannot map another char
        {
        	return false;
        }
        else
        {
        	m1[s[i]] = t[i];
        	m2[t[i]] = s[i];
        }
    }
    return true;
}

int main()
{

	return 0;
}