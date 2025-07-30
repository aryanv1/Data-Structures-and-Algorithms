#include <bits/stdc++.h>
using namespace std;
#define ll long long int

stack<long long> s;
long long mini = INT_MAX;

MinStack() {

}

void push(int el) {
	long long val = el;
	if(s.empty())
	{
		mini = val;
		s.push(val);
	}
	else
	{
		if(val < mini)
		{
			s.push(2*val-mini);
			mini = val;
		}
		else
		{
			s.push(val);
		}
	}
}

void pop() {
	if(s.empty()) return ;
	if(s.top() < mini)
	{
		mini = 2*mini - s.top();
	}
	s.pop();
}

int top() {
	if(s.empty()) return -1;
	if(s.top() < mini)
	{
		return mini;
	}
	return s.top();
}

int getMin() {
	return mini;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(1)
// Time Complexity - O(1) not considering stack space

// Another Method using pair in which we maintain mini with each adding value in stack by:
// mini = min(val, st.top().second)

// modifying val of new top if we encounter lesser than mini val:
// new top = 2*val - mini

// If while retrieving, val of top is less than mini than it is modified val
// So to while popping the mini val we have to update the mini
// for prev mini = 2*mini - top_val(modified one)

// For getting the top value if modified, then the mini value will be the original top value of modified top