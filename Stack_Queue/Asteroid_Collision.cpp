#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(n)
// Space Complexity - O(n)
vector<int> asteroidCollision(vector<int>& asteroids) 
{
	int n = asteroids.size();
	stack<int> st;
	for(int i=0; i<n; i++)
	{
		bool f = 0;
		while(!st.empty() && asteroids[i]<0 && st.top()>0)
		{
			int k = st.top() + asteroids[i];
			if(k < 0)
				st.pop();
			else if(k > 0)
			{
				f = 1;
				break;
			}
			else
			{
				f = 1;
				st.pop();
				break;
			}
		}
		if(f == 0) // Only push if incomming asteroid is not destroyed. for f == 1 cases asteroid will be destroyed
			st.push(asteroids[i]);
	}
	int k = st.size();
	vector<int> ans(k);
	k = k-1;
	while(!st.empty())
	{
		ans[k] = st.top();
		st.pop();
		k--;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	vector<int> asteroids;
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		asteroids.push_back(a);
	}
	vector<int> ans = asteroidCollision(asteroids);
	for(int i=0; i<ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
// 10,2,-5