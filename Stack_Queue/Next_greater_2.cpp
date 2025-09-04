#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Time - O(n), Space - O(n)
vector<int> nextGreaterElements(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
            st.pop();
        if (st.empty())
            ans[i % n] = -1;
        else
            ans[i % n] = st.top();
        st.push(arr[i % n]);
    }
    return ans;
}

int main()
{

    return 0;
}