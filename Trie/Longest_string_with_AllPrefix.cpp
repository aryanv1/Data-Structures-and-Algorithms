#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node
{
	Node *links[26];
	bool flag = false;

	bool containsKey(char ch)
	{
		return (links[ch-'a'] != NULL);
	}

	Node* get(char ch)
	{
		return links[ch-'a'];
	}

	void setEnd()
	{
		flag = true;
	}

	void put(char ch, Node *node)
	{
		links[ch-'a'] = node;
	}

	bool isEnd()
	{
		return flag;
	}
};

class Trie
{
private:
	Node *root;

public:
	Trie()
	{
		root = new Node();
	}

	void insert(string word)
	{
		Node *node = root;
		for(int i=0; i<word.size(); i++)
		{
			if(!node->containsKey(word[i]))
			{
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool check(string a)
	{
		Node *node = root;
		for(int i=0; i<a.size(); i++)
		{
			if(node->containsKey(a[i]))
			{
				node = node->get(a[i]);
				if(node->isEnd() == false)
					return false;
			}
			else
				return false;
		}
		return true;
	}
};

class Solution
{
public:
	string longestString(vector<string> &words)
	{
        // code here
		Trie* t = new Trie();
		int n = words.size();
		for(int i=0; i<n; i++)
		{
			t->insert(words[i]);
		}

		string ans = "";
		for(int i=0; i<n; i++)
		{
			if(t->check(words[i]))
			{
				if(words[i].size() > ans.size())
				{
					ans = words[i];
				}
				else if(words[i].size() == ans.size())
				{
					if(words[i] < ans)
						ans = words[i];
				}
			}
		}
		return ans;
	}
};

int main()
{
	
	return 0;
}

// Time Complexity - O(N*lenOfString)