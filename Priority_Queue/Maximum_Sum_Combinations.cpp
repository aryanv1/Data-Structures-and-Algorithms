#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> solve(vector<int> &A, vector<int> &B, int C) 
{
	int n = A.size();
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	vector<int> ans;
	priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s; // to make sure that same indices donot occur twice
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    while(C--)
    {
    	auto it = pq.top();
    	pq.pop();
    	int sum = it.first;
    	int i = it.second.first;
    	int j = it.second.second;
    	ans.push_back(sum);
    	if(s.find({i-1,j}) == s.end())
    	{
    		pq.push({A[i-1]+B[j],{i-1,j}});
    		s.insert({i-1,j});
    	}
    	if(s.find({i,j-1}) == s.end())
    	{
    		pq.push({A[i]+B[j-1],{i,j-1}});
    		s.insert({i,j-1});
    	}
    }
    return ans;
}


int main()
{
	
	return 0;
}