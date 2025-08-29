#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
	int n = nums1.size();
	int m = nums2.size();
	int arr[m];
	stack<int> st;
	unordered_map<int,int> mt;
	for(int i=m-1; i>=0 ;i--)
	{
		mt[nums2[i]] = i;
		if(st.empty())
			arr[i] = -1;
		else
		{
			while(!st.empty() && st.top() <= nums2[i])
				st.pop();
			if(st.empty())
				arr[i] = -1;
			else
				arr[i] = st.top();
		}
		st.push(nums2[i]);
	}
	vector<int> ans;
	for(int i=0; i<n; i++)
	{
		int ind = mt[nums1[i]];
		ans.push_back(arr[ind]);
	}
	return ans;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> num1,num2;
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		num1.push_back(a);
	}
	for(int i=0; i<m; i++)
	{
		int a;
		cin>>a;
		num2.push_back(a);
	}
	vector<int> ans = nextGreaterElement(num1,num2);
	for(int i=0; i<n; i++)
		cout<<ans[i]<<endl;

	return 0;
}

// 4 1 2
// 1 3 4 2

// If the que is like - if you don't find a greater element on right then look on left side(circular array) and find greater element
// In this case we just have to replace i with i%n and run the loop till i<2*n
// We are looping from 2*n-1 to 0
// So that we can maintain the stack for right side elements first and then left side elements
// Here we can do by doubling the array and not considering second part of array for answer and just for finding greater element
// But that will take O(2n) space
// So we can just use i%n to get the index of original array

// Time Complexity - O(2n)
// Space Complexity - O(n)