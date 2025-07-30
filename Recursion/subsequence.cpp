#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int arr[], int n,int ind, vector<vector<int>> &v, vector<int> &d)
{
	if(ind>=n)
	{
		v.push_back(d);
		return;
	}

	//pick it
	d.push_back(arr[ind]);
	solve(arr,n,ind+1,v,d);
	//donot pick
	d.pop_back();
	solve(arr,n,ind+1,v,d);
}

int main()
{
	int n = 3;
	int arr[5] = {1,2,3};
	vector<int> d;
	vector<vector<int>> v;
	solve(arr,n,0,v,d);
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v[i].size(); j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}