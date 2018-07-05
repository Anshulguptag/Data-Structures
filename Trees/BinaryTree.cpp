#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
} ;
Node* FindMin(Node* root)
{
    while(root->left!=NULL)
        root = root->left;
    return root;
}
Node* newnode(int x)
{
    Node* node = new Node;
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

Node* Insert(Node* root, int x)
{
    if(root==NULL)
    {
        return newnode(x);
    }
    if(root->data > x)
        root->left = Insert(root->left,x);
    else
        root->right = Insert(root->right,x);
    return root;
}

Node* Delete(Node* root, int x)
{
    if(root==NULL)
    {
        cout<<"Cannot Delete ";
        return root;
    }
    else if(root->data > x) root->left = Delete(root->left, x);
    else if(root->data < x) root->right = Delete(root->right,x);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
         delete root;
         root = NULL;
         return root;
        }
        else if(root->left==NULL)
        {
          Node *temp = root;
          root = root->right;
          delete temp;
          return root;
        }
        else if(root->right==NULL)
        {
          Node *temp = root;
          root = root->left;
          delete temp;
          return root;
        }
        else
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
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
void postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void preorder(Node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node* root =NULL;
    int arr[] = {12,5,3,7,1,9,15,13,17};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
    {
        root = Insert(root,arr[i]);
    }
    cout<<"Inorder: ";
    inorder(root);
    cout<<"\n";
    cout<<"Postorder: ";
    postorder(root);
    cout<<"\n";
    cout<<"Preorder: ";
    preorder(root);
    root = Delete(root,15);
    cout<<"\n";
    cout<<"Inorder: ";
    inorder(root);

}
