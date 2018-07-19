#include<iostream>
using namespace std;

const int rows = 2;

struct Node
{
    Node* child[rows];
    bool isLeaf;
};

Node* getNode()
{
    Node* node = new Node;
    for(int i=0;i<rows;i++)
        node->child[i]=NULL;
    node->isLeaf = false;
}

Node* Insert(Node* root,int arr[])
{
    Node* pCrawl = root;
    for(int i=0;i<5;i++)
    {
        pCrawl->child[arr[i]] = getNode();
        pCrawl = pCrawl->child[arr[i]];
    }
    pCrawl->isLeaf = true;
    return root;
}

bool Search(Node* root,int arr[])
{
    Node* pCrawl = root;
    for(int i=0;i<5;i++)
    {
        if(pCrawl->child[arr[i]]==NULL)
            return false;
        pCrawl = pCrawl->child[arr[i]];
    }

    return (pCrawl!=NULL && pCrawl->isLeaf);
}

void Print(Node* root)
{
    if(root==NULL)
        return;
    cout<<"\n";
    for(int i=0;i<2;i++)
    {
        if(root->child[i]!=NULL)
            cout<<i<<" ";
        Print(root->child[i]);
    }

}

int main()
{
    int arr[4][5] = {{0,1,0,0,1},{1, 0, 1, 1, 0},{0, 1, 0, 0, 1},{1, 1, 1, 0, 0}};
    Node* root = getNode();
    for(int i=0;i<4;i++)
        root = Insert(root,arr[i]);

    cout<<Search(root,arr[3]);
    //Print(root);
}
