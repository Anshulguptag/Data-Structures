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

bool isBST(Node* root, Node* l=NULL, Node* r=NULL)
{
    if (root==NULL)
        return true;
    if (l != NULL && root->key < l->key)
        return false;
    if (r != NULL && root->key > r->key)
        return false;
    return isBST(root->left, l, root) and
           isBST(root->right, root, r);
}
int main()
{
    Node* root = NULL;
    root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(4);
    root->right->right = newNode(3);
    cout<<isBST(root);
}
