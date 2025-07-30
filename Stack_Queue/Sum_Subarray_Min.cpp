#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int mod = (1e9+7);
int sumSubarrayMins(vector<int>& arr) 
{
	int n = arr.size();
	stack<int> st;
    vector<int> lse(n),rse(n); // right smaller element, left smaller element
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()] > arr[i]) // here we are not taking equal to because we will use in second one. If we use in both, then same elements will be counted twice.
        	st.pop();
        if(st.empty())
        	rse[i] = i;
        else
        	rse[i] = st.top();
        st.push(i);
    }
    stack<int> st1;
    for(int i=0; i<n; i++)
    {
    	while(!st1.empty() && arr[st1.top()] >= arr[i])
    		st1.pop();
    	if(st1.empty())
    		lse[i] = i;
    	else
    		lse[i] = st1.top();
    	st1.push(i);
    }
    int ans = 0;
    for(int i=0; i<n; i++)
    {
    	long long a = lse[i] == i ? i+1 : i-lse[i];
    	long long b = rse[i] == i ? n-i : rse[i]-i;
    	long long prod = (arr[i]*a*b)%mod;
    	ans = (ans + prod)%mod;
    }
    return ans%mod;
}

int main()
{
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	int ans = sumSubarrayMins(arr);
	cout<<ans<<endl;
	return 0;
}

// 3,1,2,4