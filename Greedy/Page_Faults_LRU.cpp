#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Page Fault -> if an element not present in cache is added
int pageFaults(int n, int C, int pages[])
{
	vector<int> v;
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		auto it = find(v.begin(),v.end(),pages[i]);
		int size = v.size();
		if(it == v.end())
		{
			if(size == C)
			{
				v.erase(v.begin());
				v.push_back(pages[i]);
				cnt++;
			}
			else
			{
				v.push_back(pages[i]);
				cnt++;
			}
		}
		else
		{
			v.erase(it);
			v.push_back(pages[i]);
		}
	}
	return cnt;
}

int main()
{
	
	return 0;
}

// Remove the element from cache if already present and add again the element
// If Not present and cache is full then remove the LRU element and add this