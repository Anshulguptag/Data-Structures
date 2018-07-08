#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

int Ceil(Node* root, int x)
{
    if(root==NULL) return -1;
    if(root->data==x)
        return root->data;

    if(root->data<x)
        return Ceil(root->right,x);

    int ceil = Ceil(root->left,x);

    return((ceil>=x)?ceil:root->data);
}

int main()
{
    Node *root = newNode(8);

    root->left = newNode(4);
    root->right = newNode(12);

    root->left->left = newNode(2);
    root->left->right = newNode(6);

    root->right->left = newNode(10);
    root->right->right = newNode(14);
    cout<<Ceil(root,9);
}
