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
    node->left = node->right =NULL;

    return node;
}
int Level(Node* root, int x,int level)
{
    if(root==NULL)
        return 0;
    if(root->data == x)
        return level;
    int downlevel = Level(root->left,x,level+1);
    if(downlevel!=0)
        return downlevel;
    downlevel = Level(root->right,x,level+1);
    return downlevel;
}


int main()
{
    Node* root = newNode(3);
    root->left = newNode(4);
    root->right = newNode(1);
    root->right->left = newNode(10);
    root->right->right = newNode(11);
    root->right->right->right = newNode(12);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    root->left->left->left = newNode(7);
    cout<<Level(root,6,1);

}

