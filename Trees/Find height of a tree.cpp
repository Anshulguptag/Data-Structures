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
int Height(Node* root)
{
    if(root==NULL)
        return -1;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return (max(leftHeight,rightHeight)+1);
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
    cout<<Height(root);

}
