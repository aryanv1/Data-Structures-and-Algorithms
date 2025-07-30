#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> minPartition(int n)
{
	vector<int> arr = {1,2,5,10,20,50,100,200,500,2000};
	vector<int> out;
	for(int i=9; i>=0; i--)
	{
		if(n/arr[i] >= 0)
		{
			int k = n/arr[i];
			n = n - k*arr[i];
			while(k--)
				out.push_back(arr[i]);
		}
		if(n == 0) break;
	}
	return out;
}

int main()
{
	
	return 0;
}