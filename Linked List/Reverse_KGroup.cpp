#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ListNode* reverse(ListNode* head) {
    ListNode* c = head;
    ListNode* p = NULL;
    ListNode* n = NULL;
    while (c) 
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1)
        return head;
    ListNode* curr = head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* n = curr;
    while (n) {
        int size = k;
        while(n && size > 0)
        {
            curr = n;
            n = n->next;
            --size;
        }
        if(size == 0)
        {
            curr->next = NULL;
            ListNode *rev = reverse(prev->next);
            curr = prev->next;
            curr->next = n;
            prev->next = rev;
            prev = curr;
            curr = n;
        }
    }
    return dummy->next;
}

int main()
{
	
	return 0;
}