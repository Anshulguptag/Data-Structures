#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char x)
{
    Node* node = new Node;
    node->data = x;
    node->left = node->right =NULL;

    return node;
}

void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->left = newNode('F');

    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<"\nPreorder traversal: ";
    preorder(root);
}
