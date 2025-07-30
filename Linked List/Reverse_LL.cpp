#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// For brute we can use stack based approach
// Using recursive approach
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *newNode = reverseList(head->next); // to get starting of reverse LL
    ListNode *front = head->next; // always point to end of reversed LL till there
    front->next = head;
    head->next = NULL;
    return newNode;
}
// Use iterative approach
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *curr = head;
    ListNode *n = head->next;
    ListNode *prev = NULL;
    while(curr)
    {
        curr->next = prev;
        prev = curr;
        curr = n;
        if(n)
            n = n->next;
    }
    return prev;
}

int main()
{
	
	return 0;
}