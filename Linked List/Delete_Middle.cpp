#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute - Find length and then traverse to half of it and delete the node
ListNode* deleteMiddle(ListNode* head) {
    if(!head || !head->next) return NULL;
    ListNode *fast = head->next->next;
    ListNode *slow = head;
    //start after fast's one iteration from original to get element before middle element
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main()
{
	
	return 0;
}