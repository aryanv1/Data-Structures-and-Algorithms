#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Remove Middle ELement of Stack -> Time - O(N), Space - O(N)
void solve(stack<int> &st, int cnt, int size)
{
	if(cnt == size/2)
	{
		st.pop();
		return ;
	}

	int el = st.top(); // keep the top element aside and call recursion for remaining stack
	st.pop();
	solve(st,cnt+1,size);
	st.push(el); // push that element when returning back from recursion
}

// Reverse a Stack -> Time - O(N*N), Space - O(N)
void insertAtBottom(stack<int> &st, int val)
{
	if(st.empty())
	{
		st.push(val);
		return ;
	}

	int el = st.top();
	st.pop();
	insertAtBottom(st,val);  
	st.push(el);
}

void reverseStack(stack<int> &st)
{
	if(st.empty())
		return ;

	int el = st.top();
	st.pop();
	reverseStack(st); // will give reversed stack for remaining elements and then we just have to insert the el at bottom
	insertAtBottom(st,el);
}

// Sort a Stack -> Time - O(N*N), Space - O(N)
void sortedInsert(stack<int> &st, int val)
{
	if(st.empty() || st.top() <= val) // as soon as we get an element less than inserting element, we push the inserting element
	{
		st.push(val);
		return ;
	}

	int el = st.top();
	st.pop();
	sortedInsert(st,val);
	st.push(el);
}

void sortStack(stack<int> &st)
{
	if(st.empty())
		return ;

	int el = st.top();
	st.pop();
	sortStack(st); // always think like this will give reversed remaining stack
	sortedInsert(st,el); // then just insert the el in sorted way
}

int main()
{
	
	return 0;
}