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


int isBalanced(Node* root)
{
    if(root == NULL)
        return -1;
    int lefttree = isBalanced(root->left);
    int righttree = isBalanced(root->right);

    if(lefttree-righttree>1)
        return 100000000; //treat as infinity
    return (1+max(lefttree,righttree));
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    int balanced = isBalanced(root)-1;
    if(balanced>=-1 && balanced<=1)
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
}
