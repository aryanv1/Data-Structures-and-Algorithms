#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time - O(N*N), Space - O(N)
void  insertLast(stack<int> &s, int el) {
    if(s.empty())
    {
        s.push(el);
        return ;
    }
    int top = s.top();
    s.pop();
    insertLast(s,el);
    s.push(top);
}
void Reverse(stack<int> &st) {
    if(st.empty())
        return ;
    int top = st.top();
    st.pop();
    Reverse(st);
    insertLast(st,top);
}

int main()
{
	
	return 0;
}