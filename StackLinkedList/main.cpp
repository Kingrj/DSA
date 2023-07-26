#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{

    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        cout<<"Stack is full"<<endl;
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }


}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        cout<<"Stack is empty"<<endl;
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *t;
    t=top;
    while(t!=NULL)
    {
        cout<<t->data<<endl;
        t=t->next;

    }
}

int main()
{

cout<<"Stack implementation through Linked list"<<endl;
push(10);
push(20);
push(30);

Display();

}
