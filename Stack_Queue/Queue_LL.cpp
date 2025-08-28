#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class QueueNode
{
public:

    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyQueue {
public:
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};

void MyQueue::push(int x)
{
	QueueNode* p = new QueueNode(x);
	if(rear == NULL)
	{
		front = rear = p;
	}
	else
	{
		rear->next = p;
		rear = p;
	}
}

//Function to pop front element from the queue.
int MyQueue::pop()
{
	if(front == NULL) return -1;
	int a = front->data;
	front = front->next;
	if(front == NULL) rear = NULL;
	return a;
}

int main()
{
	
	return 0;
}