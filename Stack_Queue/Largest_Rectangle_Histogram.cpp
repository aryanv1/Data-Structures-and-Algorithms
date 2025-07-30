#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int largestRectangleArea(vector<int>& heights) 
{
	int n = heights.size();
	stack<int> st;
	int ans = 0;
	for(int i=0; i<=n; i++)
	{
		// we go till n so that for every element remaining in stack we can calculate area
		while(!st.empty() && (i==n || heights[st.top()] >= heights[i]))
		{
                int h = heights[st.top()]; // element at i will be its(top()) next smaller and element just before it in stack will be its prev smaller.
                // while taking the greater element out from stack, we will compute its area accordingly
                st.pop();
                int left = st.empty() ? 0 : st.top()+1;
                int right = i-1;
                int width = right-left+1;
                ans = max(ans,h*width);
        }
        st.push(i);
    }
    return ans;
}

int main()
{
	int n;
	cin>>n;
	vector<int> heights;
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		heights.push_back(a);
	}
	int ans = largestRectangleArea(heights);
	cout<<ans<<endl;
	return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(2*N)

// This que is also solve by method of lse and rse - just frind these two for each index and then find area for every index and we are good to go.
// here timee complexity will increase since we will be trversing more number of times and space complexity will also increase because we are storing lse and rse and using stcak as well.