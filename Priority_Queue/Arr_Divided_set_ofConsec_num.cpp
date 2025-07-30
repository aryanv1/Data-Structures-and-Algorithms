#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPossibleDivide(vector<int>& hand, int groupSize) 
{
	int n = hand.size();
	map<int,int> m;
	for(int i=0; i<n; i++)
		m[hand[i]]++;
	int k = n/groupSize;
	while(k--)
	{
		int size = groupSize;
		int prev = -1;
		for(auto it : m)
		{
			if(prev == -1 || it.first-prev == 1)
				m[it.first]--;
			else return false;
			prev = it.first;
			if(m[it.first] == 0)
				m.erase(it.first);
			size--;
			if(size == 0) break;
		}
	}
	if(m.size() > 0) return false;
	return true;
}

int main()
{
	
	return 0;
}