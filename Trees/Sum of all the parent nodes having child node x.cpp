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
        return;
    if(root->left!=NULL || root->right!=NULL)
        *sum = *sum + root->data;
    Sum(root->left,sum);
    Sum(root->right,sum);

}

int main()
{
    Node *root = newNode(4);           /*        4        */
    root->left = newNode(2);           /*       / \       */
    root->right = newNode(5);          /*      2   5      */
    root->left->left = newNode(7);     /*     / \ / \     */
    root->left->right = newNode(2);    /*    7  2 2  3    */
    root->right->left = newNode(2);
    root->right->right = newNode(3);

    int sum = 0;
    Sum(root,&sum);
    cout<<sum;
}
