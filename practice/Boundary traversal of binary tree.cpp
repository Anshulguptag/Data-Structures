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

void printright(Node* root)
{
    if(root==NULL)
        return;
    printright(root->right);
    if(root->left!=NULL && root->right!=NULL)
        cout<<root->data<<" ";
}
void printLeaf(Node* root)
{
    if(root==NULL)
        return;
    if(root->left==NULL and root->right==NULL)
        cout<<root->data<<" ";
    printLeaf(root->left);
    printLeaf(root->right);
}

void printleft(Node* root)
{
    if(root==NULL)
        return;
    if(root->left!=NULL && root->right!=NULL)
        cout<<root->data<<" ";
    printleft(root->left);
}
void Print(Node* root)
{
    cout<<root->data<<" ";
    printleft(root->left);
    printLeaf(root);
    printright(root->right);
}

int main()
{
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right->right =newNode(25);

    Print(root);

}

