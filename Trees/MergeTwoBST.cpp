#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right =NULL;

    return node;
}

Node* Insert(Node* root, int data)
{
    if(root==NULL) return newNode(data);
    if(root->data>data)
        root->left = Insert(root->left,data);
    else if(root->data<data)
        root->right = Insert(root->right,data);
}

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* root2= NULL;
void BST(Node* root)
{
    if(root==NULL) return;
    BST(root->left);
    root2 = Insert(root2,root->data);
    BST(root->right);
}
void mergeTree(Node* root,Node* root1)
{
    BST(root);
    BST(root1);
    inorder(root2);
}

int main()
{
    Node* root=NULL;
    Node* root1=NULL;
    int arr[] = {1,2,8,10};
    int arr1[] = {0,3,5};
    int size = *(&arr+1)-arr;
    int size1 = *(&arr1+1)-arr1;
    for(int i=0;i<size;i++)
        root = Insert(root,arr[i]);
    cout<<"First BST: ";
    inorder(root);
    for(int i=0;i<size1;i++)
        root1 = Insert(root1,arr1[i]);
    cout<<"\nSecond BST: ";
    inorder(root1);
    cout<<"\nCombine BST: ";
    mergeTree(root,root1);
}
