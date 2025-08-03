#include <bits/stdc++.h> using namespace std; #define ll long long int

bool isPrime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

// Here not for all numbers we are checking prime so its time complexity is approx sqrt(n)*sqrt(n)
vector<int> method1(int n)
{
	vector<int> ans;
	for(int i=2; i<=n; i++) // -> O(n)
	{
		if(n%i == 0)
		{
			if(isPrime(i)) // -> O((n)^1/2)
				ans.push_back(i);
		}
	}
	return ans;
}

vector<int> method2(int n)
{
	vector<int> ans;
	for(int i=2; i*i<=n; i++) // -> O((n)^1/2)
	{
		if(n%i == 0)
		{
			if(isPrime(i)) // -> O((n)^1/2)
				ans.push_back(i);
			if((n/i) != i)
			{
				if(isPrime(n/i))
					ans.push_back(n/i);
			}
		}
	}
	return ans;
}

vector<int> method3(int n)
{
	vector<int> ans;
	for(int i=2; i*i<=n; i++) // -> O((n)^1/2)
	{
		if(n%i == 0)
			ans.push_back(i);
		while(n%i == 0) // dividing by its prime factor so multiple of it can divide it later and thus reducing value of n and time complexity -> O(log(n))
			n = n/i;
	}
	if(n != 1) ans.push_back(n); // for the case if n is prime itself then no i will divide it
	return ans;
}

int main()
{
	vector<int> ans = method1(100);
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

// For factors of n, go till sqrt(n) and follow the method2 just ignore isPrime function