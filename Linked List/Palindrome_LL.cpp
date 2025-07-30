#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute can be insert data into stack and then check till half of the size with liked list for palindrome
ListNode* reverse(ListNode *head)
{
    if(head == NULL)
    return NULL;
    if(head->next == NULL)
    return head;
    ListNode *p = head;
    ListNode *q = NULL;
    ListNode *r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

bool isPalindrome(ListNode* head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *fr = head;
    if(head == NULL)
    return 0;
    if(head->next == NULL)
    return true;
    // int cnt=0;
    while(fast && fast->next)
    {
        // if(fast->next)
        fast = (fast->next)->next;
        // if(slow)
        slow = slow->next;
        // cnt++;
    }
    fast = head;
    ListNode *rev = reverse(slow);
    while(rev)
    {
        if(rev->val != fast->val)
        return 0;
        rev = rev->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
	
	return 0;
}