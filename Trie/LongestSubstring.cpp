#include<iostream>
using namespace std;

const int alphabets = 26;

struct Node{
    Node *child[alphabets];
    bool isLeaf;
};

Node* getNode()
{
    Node* node = new Node;
    for(int i=0;i<alphabets;i++)
        node->child[i]=NULL;
    node->isLeaf = false;

    return node;
}

Node* Insert(Node* root,string str)
{
    Node* pCrawl = root;
    for(int i=0;i<str.length();i++)
    {
        if(isupper(str[i]))
            str[i] = tolower(str[i]);
        int index = str[i]-'a';
        if(pCrawl->child[index]==NULL)
            pCrawl->child[index]=getNode();
        pCrawl = pCrawl->child[index];
    }
    pCrawl->isLeaf = true;

    return root;
}

bool Searching(Node* root,string key)
{
    Node* temp = root;
    for(int i=0;i<key.length();i++)
    {
        if(isupper(key[i]))
            key[i] = tolower(key[i]);
        int index = key[i]-'a';
        if(temp->child[index]==NULL)
            return false;
        temp = temp->child[index];
    }

    return (temp!=NULL && temp->isLeaf==true);
}
string LongestPrefix(Node* root,string key)
{
    Node* temp = root;
    int i =0;
    string pref = "";
    while(temp->isLeaf!=true)
    {
        if(isupper(key[i]))
            key[i] = tolower(key[i]);
        int index = key[i]-'a';
        if(temp->child[index]==NULL)
            break;
        pref = pref + key[i];
        temp = temp->child[index];
        i++;
    }
    return pref;
}
int main()
{
    Node* root = getNode();
    string str[] = {"are", "area", "base", "cat", "cater", "children", "basement"};
    int size = *(&str+1)-str;
    for(int i=0;i<size;i++)
        root = Insert(root,str[i]);

    Searching(root,"ar");
    string findPrefixString[] = {"caterer","basement","are","arex","basemexz","xyz"};
    int size1 = *(&findPrefixString+1)-findPrefixString;
    for(int j=0;j<size1;j++)
    {
        cout<<findPrefixString[j]<<": "<<LongestPrefix(root,findPrefixString[j]);
        cout<<"\n";
    }
}
