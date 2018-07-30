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

int sum(Node* root)
{
    if(root==NULL)
        return 0;
    int oldval = root->data;

    root->data = sum(root->left) + sum(root->right);
    return (oldval + root->data);
}

int main()
{
    Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    sum(root);


}
