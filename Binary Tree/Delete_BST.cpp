#include <bits/stdc++.h>
using namespace std;
#define ll long long int

Node *deleteNode(Node *root, int key) 
{
	if(root)
	{
        if(key < root->data) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
        else if(key > root->data) root->right = deleteNode(root->right, key);       
        else{
            if(!root->left && !root->right) return NULL;          //No child condition
            if (!root->left || !root->right)
                return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
    			                                                //Two child condition   
            Node* temp = root->left;                            //(or) TreeNode *temp = root->right;
            while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
            root->data = temp->data;                            //       root->val = temp->val;
            root->left = deleteNode(root->left, temp->data);  //        root->right = deleteNode(root->right, temp);		
        }
    }
    return root;
}

int main()
{
	
	return 0;
}