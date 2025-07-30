#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next) return head;
    ListNode *t = head;
    int cnt = 0;
    while(t)
    {
        t = t->next;
        cnt++;
    }
    k = k%cnt;
    ListNode *fast = head;
    ListNode *slow = head;
    for(int i=0; i<k && fast; i++)
        fast = fast->next;
    while(fast && fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    if(fast)
        fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
}

int main()
{
	
	return 0;
}