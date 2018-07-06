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
    node->left = node->right = NULL;

    return node;
}

Node* mini(Node* root)
{
    while(root->left!=NULL)
        root = root->left;
    return root;
}

Node* maxi(Node* root)
{
    while(root->right!=NULL)
        root = root->right;
    return root;
}

Node* righttree(Node* temp, Node* temp1, int data)
{
    while(temp1->data!=data)
    {
        if(temp1->data<data)
        {
            temp = temp1;
            temp1 = temp1->right;
        }
        else if(temp1->data>data)
        {
            temp = temp1;
            temp1 = temp1->left;
        }
    }
    if(temp->data>temp1->data)
    {
       if(temp1->left!=NULL)
       {
           return maxi(temp1->left);
       }
       else
        return temp;
    }
    else
    {
      if(temp1->right!=NULL)
        {
            return mini(temp1->right);
        }
        else
            return temp1;
    }
}

Node* lefttree(Node* root,Node* temp, Node* temp1, int data)
{
    while(temp1->data!=data)
    {
        if(temp1->data<data)
        {
            temp = temp1;
            temp1 = temp1->right;
        }
        else if(temp1->data>data)
        {
            temp = temp1;
            temp1 = temp1->left;
        }
    }
    if(temp1->right!=NULL)
       {
           return mini(temp1->right);
       }
    else if(temp1->data>temp->data)
        return root;
    else
        return temp;
}

Node* inordersucc(Node* root, int data)
{
    if(root==NULL) return root;
    Node* temp = root;
    if(root->data<data)
       return righttree(temp, root->right, data);
    else
        return lefttree(root, temp, root->left, data);


}
int main()
{
    Node* root = newNode(20);
    root->right = newNode(22);
    root->right->left = newNode(21);
    root->right->right = newNode(24);
    root->right->right->left = newNode(23);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    cout<<"Inorder Successor of 10 is "<<inordersucc(root, 10)->data;
    cout<<"\nInorder Successor of 14 is "<<inordersucc(root, 14)->data;
    cout<<"\nInorder Successor of 8 is "<<inordersucc(root, 8)->data;
}
