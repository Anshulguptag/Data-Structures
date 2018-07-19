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

Node* Insert(Node* root,int x)
{
    if(root == NULL)
        return newNode(x);
    if(root->left==NULL)
        {
           root->left = newNode(x);

        }
    else if(root->right==NULL)
        {
           root->right = newNode(x);
        }
    else
    {
        if(root->left->left==NULL)
            Insert(root->left,x);
        else if(root->left->right==NULL)
            Insert(root->left,x);
        else if(root->right->left==NULL)
            Insert(root->right,x);
        else if(root->right->right==NULL)
            Insert(root->right,x);
    }
    return root;
}
void Swap(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Print(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    Print(root->left);
    Print(root->right);
}
int main()
{
    Node* root=NULL;
    int arr[] = {1,3,6,5,9,8};
    for(int i=0;i<3;i++)
    {
        if(arr[i]>arr[2*i+1])
            Swap(&arr[i],&arr[2*i+1]);
        else if(arr[i]>arr[2*i+2])
            Swap(&arr[i],&arr[2*i+2]);

    }
    for(int i=0;i<6;i++)
    {
        root = Insert(root,arr[i]);
    }
    Print(root);
}
