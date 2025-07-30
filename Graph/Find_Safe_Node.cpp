#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> eventualSafeNodes(int n, vector<int> adj[]) 
{
	vector<int> adjr[n];
	vector<int> indegree(n,0);
	for(int i=0; i<n; i++)
	{
		for(auto it : adj[i])
		{
			adjr[it].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for(int i=0; i<n; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
		}
	}
	vector<int> ans;
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		ans.push_back(k);
		for(auto it : adjr[k])
		{
			indegree[it]--;
			if(indegree[it] == 0)
				q.push(it);
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}

int main()
{
	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	vector<int> safeNodes = eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;
	return 0;
}