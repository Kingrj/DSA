#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*Head=NULL;

void create(int A[], int n){
    struct Node *temp,*last;

    Head = new Node;
    Head -> data= A[0];
    Head -> next = Head;
    last=Head;

    for(int i=1; i<n;i++){

        temp = new Node;
        temp->data=A[i];
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }

}

void insertNode(int pos, int value){
    struct Node *t,*p;
    if(pos==0){
        t=new Node;
        t->data=value;

        if(Head==NULL){
            Head=t;
            Head->next=Head;
        }
        else{
            p=Head;
            while(p->next!=Head){
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
            Head=t;

        }
    }
    else{
        p=Head;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t=new Node;
        t->data=value;
        t->next=p->next;
        p->next=t;
    }

}

void Display(struct Node *p){
    do{
        cout<<p->data<<endl;
        p=p->next;
    }while(p!=Head);

}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    insertNode(0,0);
    Display(Head);
    return 0;
}
