#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
int data;
struct Node *next;
}*fptr=NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *temp, *last;
    fptr=(struct Node *)malloc(sizeof(struct Node));
    fptr->data=A[0];
    fptr->next=NULL;
    last=fptr;

    for(i=1;i<n;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void Display(struct Node *P)
{
    while(P!=NULL)
    {
        cout<<P->data<<endl;
        P=P->next;
    }
}

void RecDisplay(struct Node *P)
{

    if(P!=NULL)
    {
        cout<<P->data<<endl;
        Display(P->next);
    }
}
int main()
{
    int A[]={3,5,7,10,15};
    Create(A,5);

    Display(fptr);
    RecDisplay(fptr);
}
