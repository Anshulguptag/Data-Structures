#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int x)
{
    Node* node = new Node;
    node->key = x;
    node->left = node->right = NULL;

    return node;
}

Node* LCA(Node* root, int n1, int n2)
{

    if(n1>root->key && n2>root->key)
        return LCA(root->right,n1,n2);
    if(n1<root->key && n2<root->key)
        return LCA(root->left,n1,n2);
    return root;
}

int main()
{
    Node* root = NULL;
    root = newNode(5);
    root->left = newNode(3);
    root->left->right = newNode(4);
    root->left->left = newNode(2);
    root->left->left->left = newNode(1);
    root->right = newNode(7);
    root->right->left = newNode(6);
    root->right->right = newNode(8);

    cout<<"LCA of 7 and 4: "<<LCA(root,7,4)->key;
}
