#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute - Calculate the length of the list and subtract given n from that and delete the node 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *prev = head;
    ListNode *curr = head;
    while(n--)
        curr = curr->next;
    while(curr && curr->next)
    {
        curr = curr->next;
        prev = prev->next;
    }
    if(prev->next)
    prev->next = prev->next->next;
    return head;
}

int main()
{
	
	return 0;
}