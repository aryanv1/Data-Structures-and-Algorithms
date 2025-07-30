#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int method1(int n)
{
	vector<int> prime(n+1,1);
	for(int i=2; i<=n; i++)
	{
		if(prime[i] == 1)
		{
			for(int j=i*i; j<=n; j+=i) // also start with j=2*i i.e, first multiple if i but that will be already marked by previous prime number 
				prime[j] = 0;
		}
	}
	int cnt = 0;
	for(int i=2; i<=n; i++)
	{
		if(prime[i] == 1)
			cnt++;
	}
	return cnt;
}

int method2(int n)
{
	vector<int> prime(n+1,1);
	// Time complexity of below loop is O(Nlog(logN)) -> mathematically proven
	for(int i=2; i*i<=n; i++) // Prime number will come till sqrt(n) only
	{
		if(prime[i] == 1)
		{
			for(int j=i*i; j<=n; j+=i)
				prime[j] = 0;
		}
	}
	int cnt = 0;
	// Time Complexity - O(n)
	for(int i=2; i<=n; i++)
	{
		if(prime[i] == 1)
			cnt++;
	}
	return cnt;
}

int main()
{
	int ans = method1(10);
	cout<<ans<<endl;
	return 0;
}