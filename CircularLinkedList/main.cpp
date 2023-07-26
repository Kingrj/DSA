#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{

int data;
struct Node *next;

}*Head=NULL;

void create(int A[], int n)
{
    struct Node *last, *temp;
    int i;
    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1;i<n;i++)
    {

        temp=new Node;
        temp->data=A[i];
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}

void Display(struct Node *p)
{
    do{
        cout<<p->data<<endl;
        p=p->next;
    }while(p!=Head);

}

void RDisplay(struct Node *p)
{
    static int flag=0;
    if(p!=Head || flag==0)
    {
        flag=1;
        cout<<p->data<<endl;
        RDisplay(p->next);


    }
}

int countNodes(struct Node *p)
{
    int count=0;
    do{
        count=count+1;
        p=p->next;
    }while(p!=Head);
    return count;
}


int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);

    //Display(Head);
    RDisplay(Head);
    int countNode=countNodes(Head);
    cout<<"Nodes:"<<countNode;


}
