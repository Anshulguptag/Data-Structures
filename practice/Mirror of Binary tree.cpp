#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x)
{
    Node* node = new Node;
    node->data = x;
    node->left = node->right = NULL;

    return node;
}


void Mirror(Node* root)
{
    if(root==NULL)
        return ;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    Mirror(root->left);
    Mirror(root->right);
}

void Print(Node* root)
{
    if(root==NULL)
        return;
    Print(root->left);
    cout<<root->data;
    Print(root->right);
}
int main()
{
    Node* root = newNode(1);
    Node* root1 = newNode(root->data);

    root->left = newNode(3);
    root->right = newNode(2);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout<<"Inorder traversal of the constructed tree is: ";
    Print(root);

    Mirror(root);

    cout<<"\nInorder traversal of the mirror tree is : ";
    Print(root);



}
