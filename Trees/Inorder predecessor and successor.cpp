#include<iostream>.
using namespace std;

struct Node{
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

Node* Insert(Node* root, int x)
{
    if(root==NULL)
        return newNode(x);
    if(root->key > x)
        root->left = Insert(root->left, x);
    else if(root->key < x)
        root->right = Insert(root->right, x);
}

void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int x)
{
    if(root==NULL)
        return;
    if(root->key == x)
    {
        if(root->left!=NULL)
        {
            Node* temp = root->left;
            while(temp->right!=NULL)
                temp = temp->right;
            pre = temp;
        }
        if(root->right!=NULL)
        {
            Node* temp = root->left;
            while(temp->left!=NULL)
                temp = temp->left;
            suc = temp;
        }
        return ;
    }
    if(root->key > x)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, x);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, x);
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
    Node* pre = NULL;
    Node* suc = NULL;
    findPreSuc(root, pre, suc, 12);
    cout<<"\n";
    if(pre!=NULL)
        cout<<"Predecessor is "<<pre->key<<endl;
    else
        cout<<"No Predecessor ";
    if(suc!=NULL)
        cout<<"Successor is "<<suc->key<<endl;
    else
        cout<<"No Successor ";

}
