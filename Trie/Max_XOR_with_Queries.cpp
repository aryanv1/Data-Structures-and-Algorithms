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
	static bool comp(vector<int> a, vector<int> b)
	{
		return a[1] < b[1];
	}
	vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size();
		int q = queries.size();
		Trie *t = new Trie();
		sort(nums.begin(),nums.end());
		for(int i=0; i<q; i++)
			queries[i].push_back(i);
        sort(queries.begin(),queries.end(),comp); // sort according to m and not x 

        int k = 0;
        vector<int> ans(q);
        for(int i=0; i<q; i++)
        {
        	int num = queries[i][0];
        	int m = queries[i][1];
        	int ind = queries[i][2];

        	while(k<n && nums[k] <= m)
        		t->insert(nums[k++]);

        	if(nums[0] <= m)
        		ans[ind] = t->getMax(num);
        	else
        		ans[ind] = -1;
        }
        return ans;
    }
};

int main()
{
	
	return 0;
}

// Do the same thing as before but the simple change is sort the array and queries, queries acc to m, and then only insert elements till m and calculate XOR till there.