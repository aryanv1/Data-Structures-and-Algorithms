#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute can be using map -> keep track of already visited nodes
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = (fast->next)->next;
        slow = slow->next;
        if(fast== slow)
        return 1;
    }
    return 0;

int main()
{
	
	return 0;
}