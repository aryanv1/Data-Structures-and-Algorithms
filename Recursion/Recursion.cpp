#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool is_sorted(int *arr, int n)
{
	if(n == 0 || n == 1) return true;
	if(arr[0] > arr[1])
		return false;
	else
		return is_sorted(arr+1,n-1);
}

int sum(int arr[],int n)
{
	//base case
	if(n <= 0)
		return 0;

	//recursive relation
	int s = arr[n-1] + sum(arr,n-1);
	return s;
}

bool Lsearch(int arr[], int n, int key)
{
	//base case
	if(n == 0) return false;
	if(arr[n-1] == key) return true;
	else
	{
		// recursive relation
		int remaining = Lsearch(arr,n-1,key);
		return remaining;
	}
}

bool BinSearch(int arr[], int low, int high, int key)
{
	int mid = (low+high)/2;
	//element not found
	if(low>high) return false;
	//element found
	if(arr[mid] == key)
		return true;
	else if(arr[mid] > key)
		return BinSearch(arr,low,mid-1,key);
	else
		return BinSearch(arr,mid+1,high,key);
}

void reverse(string &s,int start,int end)
{
	if(start > end)
		return ;
	swap(s[start],s[end]);
	start++;
	end--;
	reverse(s,start,end);
}

long long power(int x, int n)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return x;
	ll ans = power(x,n/2);
	if(n%2 == 0)
		return ans*ans;
	else
		return x*ans*ans;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	string s = "Aryan";
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<power(2,10)<<endl;
	return 0;
}