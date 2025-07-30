#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node {
	Node *links[2];

	bool containsKey(int bit)
	{
		return links[bit] != NULL;
	}

	void put(int bit, Node *node)
	{
		links[bit] = node;
	}

	Node *get(int bit)
	{
		return links[bit];
	}
};

class Trie{
private:
	Node *root;
public:
	Trie() {
		root = new Node();
	}

	void insert(int num)
	{
		Node *node = root;
		for(int i=31; i>=0; i--)
		{
			int k = (num >> i) & 1;
			if(!node->containsKey(k))
			{
				node->put(k, new Node());
			}
			node = node->get(k);
		}
	}

	int getMax(int num)
	{
		Node *node = root;
		int ans = 0;
		for(int i=31; i>=0; i--)
		{
			int k = (num >> i) & 1;
			if(node->containsKey(1-k)) 
			{
				ans = ans | (1 << i);
				node = node->get(1-k);
			}
			else
				node = node->get(k);
		}
		return ans;
	}
};

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		Trie *t = new Trie();
		int n = nums.size();
		for(int i=0; i<n; i++)
		{
			t->insert(nums[i]);
		}
		int maxi = 0;
		for(int i=0; i<n; i++)
		{
			maxi = max(maxi, t->getMax(nums[i]));
		}
		return maxi;
	}
};

int main()
{
	
	return 0;
}

// Time Complexity - O(2 * n * 32)