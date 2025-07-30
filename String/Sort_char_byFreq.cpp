#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string frequencySort(string s) {
	int n = s.length();
	vector<int> count(128);
	vector<vector<char>> bucket(n + 1);
	for (char c : s)
		count[c]++;
	for (int i = 0; i < 128; i++) 
	{
		if (count[i] > 0)
                bucket[count[i]].push_back(char(i)); // char(i) gives char with ascii value i
    }
    string ans;
    for (int f = n; f >= 0; f--) 
    {
    	for (char c : bucket[f])
    	{
    		int cnt = f;
    		while(cnt--)
    			ans += c;
    	}
    }
    return ans;
}

// Another method
string frequencySort(string s) 
{
    int n = s.size();
    unordered_map<char,int> m;
    for(int i=0; i<n; i++)
        m[s[i]]++;
    priority_queue<pair<int,char>> pq;
    for(auto it : m)
    {
        pq.push({it.second,it.first});
    } 
    string ans = "";
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int cnt = it.first;
        char c = it.second;
        while(cnt--)
        ans += c;
    }
    return ans;
}

// custom comparator for prioirty queue
// first element in descending and second in ascending
struct comp
{
    bool operator()(const pair<int,int> &below, const pair<int,int> &above)
    {
        if (below.first != above.first)
            return (below.first < above.first);
        else
           return (below.second > above.second);
    }
    // the conditions are reverse because consider below and above as first elemnt comes below and next elemnt above it(like stack)
};

int main()
{

	return 0;
}