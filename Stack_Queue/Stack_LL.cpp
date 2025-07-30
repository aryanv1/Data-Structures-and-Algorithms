#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void MyStack ::push(int x) 
{
	StackNode *p = new StackNode(x);
	if(top != NULL)
		p->next = top;
	top = p;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
	if(top == NULL) return -1;
	int a = top->data;
	top = top->next;
	return a;
}

int main()
{
	
	return 0;
}