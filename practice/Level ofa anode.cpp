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

int GetLevel(Node* root, int data,int l)
{
    if(root==NULL)
        return 0;
    if(root->data == data)
        return l;
    int downlevel = GetLevel(root->left,data,l+1);
    if(downlevel!=0)
        return downlevel;
    downlevel = GetLevel(root->right,data,l+1);
    return downlevel;
}

int main()
{
    Node* root = newNode(3);
    root->left = newNode(2);
    root->left->left = newNode(1);
    root->right = newNode(5);
    root->right->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right->right = newNode(7);
    cout<<GetLevel(root,6,1);

}
