#include <iostream>

using namespace std;


struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[],int n){
    struct Node *temp,*last;

    first = new Node;
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){

        temp = new Node;
        temp->prev=last;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;

    }


}

void insertNode(int pos, int value){
    struct Node *t;
    if(pos==0){
        t=new Node;
        t->prev=NULL;
        t->data=value;
        t->next=first;
        first=t;
        }
    else {
        struct Node *p=first;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }

        t= new Node;
        t->next=p->next;
        t->data=value;
        t->prev=p;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }

}

void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    Display(first);
    cout<<endl<<"After Insertion: "<<endl;
    insertNode(0,0);
    insertNode(5,80);
    Display(first);
    return 0;
}
