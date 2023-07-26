#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*frontp=NULL,*rearp=NULL;


void enqueue(int x)
{
    struct Node *p;
    p=new Node;
    if(p==NULL)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        p->data=x;
        p->next=NULL;
        if(frontp==NULL)
        {
            frontp=rearp=p;
        }
        else
        {
            rearp->next=p;
            rearp=p;
        }

    }

}

int dequeue()
{

    int x=-1;
    struct Node *p;

    if(frontp==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        x=frontp->data;
        p=frontp;
        frontp=frontp->next;
        free(p);
    }
    return x;
}

void Display()
{

    struct Node *p=frontp;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    Display();

    dequeue();
    Display();
}
