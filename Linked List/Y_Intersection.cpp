#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *d1 = headA;
    ListNode *d2 = headB;
    while(d1 != d2)
    {
        if(d1 == NULL && d2)
        {
            d1 = headB;
        }
        else if(d2 == NULL && d1)
        {
            d2 = headA;
        }
        else
        {
            d1 = d1->next;
            d2 = d2->next;
        }
    }
    return d1;
}	

int main()
{
	
	return 0;
}