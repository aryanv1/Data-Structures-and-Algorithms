#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> SPF(int n)
{
	vector<int> spf(n+1);
	for(int i=0; i<=n; i++)
		spf[i] = i;
	// Putting the number itself in the array and updating when first prime factor comes
	// O(N * log(log(N)))
	for(int i=2; i*i<=n; i++)
	{
		if(spf[i] == i)
		{
			for(int j=i*i; j<=n; j+=i)
			{
				if(spf[j] == j) // so that we can get the smallest number which divides it
					spf[j] = i;
			}
		}
	}
	vector<int> ans;
	// O(log2(n)) -> when only 2 is prime factor other it will rduce more
	while(n != 1)
	{
		ans.push_back(spf[n]);
		n = n/spf[n];
	}
	return ans;
}

int main()
{
	vector<int> ans = SPF(12246);
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

// Can also be solved using the method of Prime factor till N -> where inside while loop while eliminating the multiples we can add them into our vector