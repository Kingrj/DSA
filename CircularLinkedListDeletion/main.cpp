#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head=NULL;

void create(int A[], int n){
    struct Node *temp,*last;

    Head = new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data=A[i];
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }

}

int DeleteNode(int pos){
    struct Node *p,*q;
    int x;
    if(pos==1){
        p=Head;
        while(p->next!=Head){
            p=p->next;
        }
        x=Head->data;
        if(p==Head){
           delete Head;
           Head=NULL;
           }
        else
        {
            p->next=Head->next;
            delete Head;
            Head=p->next;
        }

    }

    else{
        p=Head;
        q=NULL;
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;

}

void Display(struct Node *p){
    do{
        cout<<p->data<<endl;
        p=p->next;
    }while(p!=Head);
}

int main()
{
    int A[] = {1,2,3,4,5};
    create(A,5);
    Display(Head);
    int data=DeleteNode(3);
    cout<<"Deleted: "<<data<<endl;
    Display(Head);
    return 0;
}
