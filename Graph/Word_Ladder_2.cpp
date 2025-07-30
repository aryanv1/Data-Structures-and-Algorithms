#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordlist) {
	vector<vector<string>> ans;
	queue<vector<string>> q;
	unordered_set<string> s(wordlist.begin(),wordlist.end());
	q.push({beginWord});
	vector<string> used;
	int lev = 0;
	used.push_back(beginWord);
	while(!q.empty())
	{
		vector<string> vec = q.front();
		q.pop();
		if(vec.size() > lev)
		{
			lev++;
			for(auto it : used)
				s.erase(it);
			used.clear();
		}
		string word = vec.back();
		if(word == endWord)
		{
			if(ans.size() == 0)
			{
				ans.push_back(vec);
			}
			else if(vec.size() == ans[0].size())
			{
				ans.push_back(vec);
			}
			else break;
		}
		for(int i=0; i<word.size(); i++)
		{
			char original = word[i];
			for(char c='a'; c<='z'; c++)
			{
				word[i] = c;
				if(s.find(word) != s.end())
				{
					vec.push_back(word);
					q.push(vec);
					used.push_back(word);
					vec.pop_back();
				}
			}
			word[i] = original;
		}
	}
	return ans;
}

int main()
{
	
	return 0;
}