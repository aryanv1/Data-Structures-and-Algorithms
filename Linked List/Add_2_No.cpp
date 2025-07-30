#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ListNode* addTwoNumbers(ListNode* r1, ListNode* r2) {
    // ListNode *r1 = reverse(l1);
    // ListNode *r2 = reverse(l2);
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    int carry = 0;
    while(r1 || r2 || carry)
    {
        int sum = carry;
        if(r1)
        sum += r1->val;
        if(r2)
        sum += r2->val;
        temp->next = new ListNode(sum%10);
        carry = sum/10;
        temp = temp->next;
        if(r1)
        r1 = r1->next;
        if(r2)
        r2 = r2->next;
    }
    return (dummy->next);
}

int main()
{
	
	return 0;
}