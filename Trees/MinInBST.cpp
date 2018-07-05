#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* right;
  Node* left;
};

Node* newNode(int x)
{
    Node* node = new Node;
    node->data = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* Insert(Node* root, int x)
{
    if(root==NULL)
        return newNode(x);

    if(root->data>x)
        root->left = Insert(root->left,x);

    else if(root->data<x)
        root->right = Insert(root->right,x);
}
int FindMin(Node* root)
{
    while(root->left!=NULL)
        root = root->left;
    return root->data;
}
void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;
    int arr[] = {12,5,3,7,1,9,15,13,17};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
    {
        root = Insert(root,arr[i]);
    }
    cout<<"Inorder: ";
    inorder(root);
    cout<<"\nMinimum Element is: ";
    cout<<FindMin(root);
}
