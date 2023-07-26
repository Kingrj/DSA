#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{

int data;
struct Node *next;

}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *last, *temp;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        temp=new Node;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }

}

int Display(struct Node *p){


    while(p!=NULL){

        cout<<p->data<<endl;
        p=p->next;

}


}

int Count(struct Node *p){

    int count=0;

    while(p!=NULL){

        count=count+1;
        p=p->next;

}

return count;

}

void insertHeadNode(){

    struct Node *Head;
    Head=new Node;
    Head->data=60;
    Head->next=first;
    first=Head;

}

void NodeAtAnyIndex(struct Node *p, int value, int pos)
{

    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    struct Node *Node_ABC;
    Node_ABC=new Node;
    Node_ABC->data=value;
    if(p->next!=NULL){
    Node_ABC->next=p->next;
    p->next=Node_ABC;
    }
}


int main(){

    int A[]={10,20,30,40,50};

    create(A,5);
    insertHeadNode();
    NodeAtAnyIndex(first,70,4);
    Display(first);
    int count_nodes=Count(first);
    cout<<"Nodes:"<<count_nodes;

}
