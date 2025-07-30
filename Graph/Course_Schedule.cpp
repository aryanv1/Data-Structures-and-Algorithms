#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> findOrder(int n, int m, vector<vector<int>> arr) 
{
	vector<int> indegree(n,0);
	vector<int> ans;
	queue<int> q;
	vector<int> adj[n];
	for(int i=0; i<m; i++)
	{
		adj[arr[i][1]].push_back(arr[i][0]);
	}
	for(int i=0; i<n; i++)
	{
		for(auto it : adj[i])
		{
			indegree[it]++;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(indegree[i] == 0)
			q.push(i);
	}
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto it : adj[node])
		{
			indegree[it]--;
			if(indegree[it] == 0)
				q.push(it);
		}
	}
	if(ans.size() == n) return ans;
	return {};
}

int main()
{
	int N = 4;
	int M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	vector<int> ans = findOrder(N, M, prerequisites);

	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}