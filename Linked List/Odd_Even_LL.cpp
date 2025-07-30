#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    while(even && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{
	
	return 0;
}