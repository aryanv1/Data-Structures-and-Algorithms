#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute - Store elements in array and then sort it and again put into list
// Optimal - merge two vertical list from end and then using recursion keep on merging till start
Node* merge(Node *root1, Node *root2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while(root1 && root2)
    {
        if(root1->data < root2->data)
        {
            temp->bottom = root1;
            temp = temp->bottom;
            root1 = root1->bottom;
        }
        else
        {
            temp->bottom = root2;
            temp = temp->bottom;
            root2 = root2->bottom;
        }
    }
    
    if(root1)
        temp->bottom = root1;
    else if(root2)
        temp->bottom = root2;
        
    return dummy->bottom;
}
Node *flatten(Node *root) {
    // Your code here
    if(!root || !root->next)
        return root;
    Node *t1 = root;
    Node *t2 = flatten(root->next);
    return merge(t1,t2);
}

int main()
{
	
	return 0;
}