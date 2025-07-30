#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void deleteAllOccurOfX(struct Node** head_ref, int x) {
    // Write your code here
    struct Node *temp = new Node();
    temp->data = -1;
    temp->next = *head_ref;
    (*head_ref)->prev = temp;
    struct Node *curr = temp;
    while(curr)
    {
        if(curr->data == x)
        {
            if(curr->prev)
                curr->prev->next = curr->next;
            if(curr->next)
                curr->next->prev = curr->prev;
        }
        curr = curr->next;
    }
    *head_ref = temp->next;
}

int main()
{
	
	return 0;
}