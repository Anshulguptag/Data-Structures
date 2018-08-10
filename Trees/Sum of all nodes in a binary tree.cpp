#include<iostream>
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

void Sum(Node* root,int *sum)
{
    if(root==NULL)
        return ;
    *sum = *sum + root->data;
    Sum(root->left,sum);
    Sum(root->right,sum);
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    int sum = 0;
    Sum(root,&sum);
    cout<<sum;
}
