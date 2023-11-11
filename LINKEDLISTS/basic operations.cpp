#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};

//traverse function
void traverse(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

//insert at begin
void insertbegin(node*& head,int ele)
{
    struct node* newnode=new node;
    newnode->data=ele;
    newnode->next=head;
    head=newnode;
}

//insert anywhere
void insertanywhere(node* head,int ele,int pos)
{
    struct node* newnode=new node;
    newnode->data=ele;
    newnode->next=NULL;

    if(pos<0)
    {
        cout<<"insertion is not possible";
        return;
    }
    if(pos==1)
    {
        newnode=head;
        head=newnode;
        return;
    }

    struct node* current=head;
    for(int i=1;i<pos-1 && current->next!=NULL;i++)
    {
        current=current->next;
    }

    if(current->next==NULL)
    {
        cout<<"index out of bounds";
        return;
    }

    newnode->next=current->next;
    current->next=newnode;
    return;
}

//insertend
void insertend(node* head,int ele)
{
    struct node* newnode=new node;
    newnode->data=ele;
    newnode->next=NULL;
    struct node* current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;

}

//deletion when the value is given
void deletionval(node*& head,int ele)
{
    if(head==NULL)
    {
        cout<<"deletion not possible";
        return;
    }
    if(head->data==ele)
    {
        struct node* temp=head;
        head=head->next;
        delete temp;
        return;
    }

    struct node* current=head;
    while(current->next!=NULL && current->next->data!=ele)
    {
        current=current->next;
    }

    if(current->next==NULL)
    {
        cout<<"element is not found";
    }
    struct node* temp=current->next;
    current->next=current->next->next;
    delete temp;
    return;
}

//deletion when the position is given
void deletionpos(node*& head,int pos)
{
    if(pos<0)
    {
        cout<<"deletion not possible";
        return;
    }
    if(pos==1)
    {
        struct node* temp=head;
        head=head->next;
        delete temp;
        return;
    }

    struct node* current=head;
    for(int i=1;i<pos-1 && current->next!=NULL; i++)
    {
        current=current->next;
    }

    if(current->next==NULL)
    {
        cout<<"index out of bounds";
        return;
    }
    struct node* temp=current->next;
    current->next=current->next->next;
    delete temp;
    return;
}

//search operation
int searchele(node*& head,int ele)
{
    int pos=1;
    struct node* current=head;
    while(current!=NULL)
    {
        if(current->data==ele)
        {
            return pos;
        }
        else
        {
            pos++;
            current=current->next;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;

    struct node* head=NULL;
    struct node* current=NULL;

    for(int i=1;i<=n;i++)
    {
        int value;
        cin>>value;

        if(head==NULL)
        {
            head=new node;
            head->data=value;
            head->next=NULL;
            current=head;
        }
        else
        {
            current->next=new node;
            current=current->next;
            current->data=value;
            current->next=NULL;

        }
    }

    int ele;
    cin>>ele;

    //int pos;
    //cin>>pos;
    //insertbegin(head,ele);
    //insertanywhere(head,ele,pos);
    //insertend(head,ele);
    //deletionval(head,ele);
    //deletionpos(head,pos);
    //traverse(head);
    int res=searchele(head,ele);
    cout<<res;
    
}
