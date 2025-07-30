#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute - For random  pointer, just keep mapping of deep copy nodes and node of original list and using the value of original node point the random pointer
// Time - O(2N), Space - O(2N)
Node *cloneLinkedList(Node *head) {
    // Write your code here
    unordered_map<Node*,Node*> m;
    Node *dummy = new Node(-1);
    Node *temp = head;
    Node *res = dummy;
    while(temp)
    {
        res->next = new Node(temp->data);
        m[temp] = res->next;
        res = res->next;
        temp = temp->next;
    }
    res = dummy->next;
    temp = head;
    while(temp)
    {
        res->random = m[temp->random];
        temp = temp->next;
        res = res->next;
    }
    return dummy->next;
}

int main()
{
	
	return 0;
}