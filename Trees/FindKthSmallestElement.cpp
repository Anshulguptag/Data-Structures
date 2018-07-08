#include<iostream>
#include<stack>
using namespace std;

stack<int> s;

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

Node* Insert(Node* root, int data)
{
    if(root==NULL) return newNode(data);
    if(root->data > data)
        root->left = Insert(root->left,data);
    else if(root->data < data)
        root->right = Insert(root->right, data);

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void Sort(Node* root)
{
    if(root==NULL) return;
    Sort(root->right);
    s.push(root->data);
    Sort(root->left);
}
int main()
{
    Node* root = NULL;
    int arr[] = {20,8,4,12,10,14,22};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
        root = Insert(root,arr[i]);
    inorder(root);
    Sort(root);
    int n =0;
    cout<<"\nEnter the value of K: ";
    int k;
    cin>>k;
    if(k>size)
    {
        cout<<"Enterd value is beyond the limit ";
    }
    else
    {
        while(n<k-1)
        {
                s.pop();
                n++;
        }
        cout<<k<<"th smallest element is: "<<s.top();

    }

}

