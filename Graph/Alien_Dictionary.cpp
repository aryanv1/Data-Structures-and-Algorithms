#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(V+E)
// Space Complexity - O(V)
// When does ordering is not possible in given dictionary?
// When there is a cycle in the graph formed by the characters.
// And when larger string is before smaller string with same prefix.
// E.g, {"abc", "ab"}
string findOrder(string dict[], int N, int K)
{
	vector<int> adj[K];
	for (int i = 0; i < N - 1; i++)
	{
		string s1 = dict[i];
		string s2 = dict[i + 1];
		int len = min(s1.size(), s2.size());
		for (int j = 0; j < len; j++)
		{
			if (s1[j] != s2[j])
			{
				adj[s1[j] - 'a'].push_back(s2[j] - 'a');
				break;
			}
		}
	}
	vector<int> ans = toposort(K, adj);
	string res = "";
	for (auto it : ans)
	{
		res = res + char(it + 'a');
	}
	return res;
}

int main()
{
	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	string ans = findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;
	return 0;
}