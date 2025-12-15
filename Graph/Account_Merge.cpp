#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(N*α(N)) , α -> Ackermann Function
// Space Complexity - O(N)
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
	int n = accounts.size();
	Disjoint_Set ds(n);
	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < accounts[i].size(); j++)
		{
			string mail = accounts[i][j];
			if (m.find(accounts[i][j]) == m.end())
			{
				m[mail] = i;
			}
			else
			{
				ds.UnionBySize(m[mail], i);
			}
		}
	}
	vector<string> ans[n];
	for (auto it : m)
	{
		string mail = it.first;
		int node = ds.findUPar(it.second);
		ans[node].push_back(mail);
	}

	vector<vector<string>> res;
	for (int i = 0; i < n; i++)
	{
		if (ans[i].size() == 0)
			continue;
		sort(ans[i].begin(), ans[i].end());
		vector<string> temp;
		temp.push_back(accounts[i][0]);
		for (auto it : ans[i])
		{
			temp.push_back(it);
		}
		res.push_back(temp);
	}
	return res;
}

int main()
{
	vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
									   {"John", "j4@com"},
									   {"Raj", "r1@com", "r2@com"},
									   {"John", "j1@com", "j5@com"},
									   {"Raj", "r2@com", "r3@com"},
									   {"Mary", "m1@com"}};

	vector<vector<string>> ans = accountsMerge(accounts);
	for (auto acc : ans)
	{
		cout << acc[0] << ":";
		int size = acc.size();
		for (int i = 1; i < size; i++)
		{
			cout << acc[i] << " ";
		}
		cout << endl;
	}
	return 0;
}