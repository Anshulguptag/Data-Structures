#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

void inordersucc(Node* root, Node*& suc, int x)
{
    if(root==NULL)
        return;
    if(root->data == x)
    {
        if(root->right!=NULL)
        {
            Node* temp = root->right;
            while(temp->left!=NULL)
                temp = temp->left;
            suc = temp;
        }
        return ;
    }
    if(root->data > x)
    {
        suc = root;
        inordersucc(root->left, suc, x);
    }
    else
    {
        inordersucc(root->right, suc, x);
    }
}


int main()
{
    Node* root = newNode(20);
    root->right = newNode(22);
    root->right->left = newNode(21);
    root->right->right = newNode(24);
    root->right->right->left = newNode(23);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    Node* succ = NULL;
    inordersucc(root,succ, 10);
    if(succ!=NULL)
    {
      cout<<"Inorder Successor of 10 is "<<succ->data;
      succ = NULL;
    }
    else
    {
        cout<<"No Successor ";
    }
    inordersucc(root,succ, 14);
    if(succ!=NULL)
    {
       cout<<"\nInorder Successor of 14 is "<<succ->data;
       succ = NULL;
    }
    else
    {
        cout<<"No Successor ";
    }
    inordersucc(root,succ, 8);
    if(succ!=NULL)
    {
        cout<<"\nInorder Successor of 8 is "<<succ->data;
        succ = NULL;
    }
    else
    {
        cout<<"No Successor ";
    }
    cout<<"\n";
    inordersucc(root,succ, 24);
    if(succ!=NULL)
    {
        cout<<"Inorder Successor of 24 is "<<succ->data;
        succ = NULL;
    }
    else
    {
        cout<<"No Successor ";
    }


}
