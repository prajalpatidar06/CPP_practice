#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linkedlist
{
public:
    node *head;

    linkedlist()
    {
        head=nullptr;
    }
    linkedlist(int C[], int n);

    void insert(node*p,int index ,int x);
    void RDisplay(node *y);
} ;

linkedlist ::linkedlist(int C[],int n)
{
    node *t,*last;

    head=new node;

    head->data=C[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=C[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void linkedlist::insert(node*p,int index ,int x)
{
    node *t;

    if(index<0 || index >6)
       exit(0);

    if(index==0)
    {
        t=new node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;            
        }
        else
        {
            for(;p!=head;p=p->next);
            p->next=t;
            t->next=head;    
            head=t;
        } 
    }
    else
    {
        t=new node;
        t->data=x;
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    } 
}


void linkedlist :: RDisplay(node *y)
{
    node *p=y;
    static int flag=0;

    if(p!=head || flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
    flag=0;
}



int main()
{
    int A[]={3,4,6,7,8,9};
    linkedlist l(A,6),l1;
    l.RDisplay(l.head);

   l.insert(l.head,4,10);
    l.RDisplay(l.head);
    
return 0;
}