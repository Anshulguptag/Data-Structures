#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NodeList
{
    int data;
    NodeList* next;
};

struct Node
{
    int data;
    NodeList* edge;
};

NodeList* Insert(NodeList* head, int x)
{
    NodeList* node = new NodeList;
    node->data = x;
    if(head==NULL)
    {
        node->next = head;
        head = node;
    }
    else
    {
        NodeList* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
    return head;
}
queue<char> path;
void DFS(vector<Node*> v,int i,bool visited[], char ch[], char target)
{
    visited[i] = true;
    path.push(ch[i]);
    if(ch[i]==target)
        return;
    NodeList* temp = v[i]->edge;
    while(temp!=NULL)
       {
            if(!visited[temp->data])
                {
                    return DFS(v,temp->data,visited,ch,target);
                    cout<<ch[temp->data]<<" ";

                }
            temp = temp->next;
       }

}
void Print(NodeList* head,char ch[])
{
    while(head!=NULL)
    {
        cout<<ch[head->data]<<"->";
        head=head->next;
    }
    cout<<"NULL";
    cout<<"\n";
}
int getIndex(char ch[], char edge, int size)
{
    int j;
   for(j=0;j<size;j++)
   {
       if(ch[j]==edge)
        break;
   }
   return j;
}
Node* InsertGraph(Node* start,int i,char ch[],int size)
{
    Node* node = new Node;
    NodeList* head = NULL;
    char ch1;
    cout<<"Do you want to connect '"<<ch[i]<<"' to any other edge(y/n): ";
    cin>>ch1;
    while(ch1=='y'|| ch1=='Y')
    {
        cout<<"Enter the Edge that you want to connect to "<<ch[i]<<" : ";
        char edge;
        cin>>edge;
        if(ch[i]!=edge)
        {
            head = Insert(head,getIndex(ch,edge,size));
            cout<<"Do you want to insert more edges: ";
            cin>>ch1;
        }
        else
        {
            cout<<"Could Not enter root edge\n ";
        }
    }
    node->data = i;
    node->edge = head;
    start = node;

    cout<<ch[node->data]<<"->";
    Print(node->edge,ch);
    cout<<"\n";
    return start;
}

int main()
{
    char ch[] = {'A','B','C','D','E','F'};
    int size = *(&ch+1)-ch;
    Node* start = NULL;
    vector<Node*> v;
    for(int i=0;i<size;i++)
    {
        v.push_back(InsertGraph(start,i,ch,size));

    }
    cout<<"\nEnter the destination path: ";
    char target;
    cin>>target;
    bool visited[size];
    for(int i=0;i<size;i++)
    {
        visited[i]=false;
    }
    cout<<"Path from A-E: ";
    DFS(v,0,visited,ch,'E');
    while(!path.empty())
    {
        cout<<path.front()<<"->";
        path.pop();
    }
    cout<<"Terminate";
}
