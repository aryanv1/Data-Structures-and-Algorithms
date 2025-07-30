#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity - O(N*N), Space Complexity - O(N)->Recursive stack space
void sortedInserted(stack<int> &st, int el)
{
    if(st.empty() || st.top() <= el)
    {
        st.push(el);
        return ;
    }
    int topElement = st.top();
    st.pop();
    sortedInserted(st,el);
    st.push(topElement);
}

void sort(stack<int> &s) {
    // Your code here
    if(s.empty())
        return ;
    int top = s.top();
    s.pop();
    sort();
    sortedInserted(s,top);
}

int main()
{
	
	return 0;
}