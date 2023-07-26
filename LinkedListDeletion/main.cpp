#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first=NULL;

void createNode(int A[], int n){

    struct Node *t,*last;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){

        cout<<"Under loop:"<<i<<endl;

        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

int Delete(int pos){
    struct Node *q,*p;
    int x=-1;

    if(pos==1){
        struct Node *d=first;
        first = first->next;
        x = d->data;
        delete d;
    }
    else{
        p=first;
        q=NULL;
        for(int i=0;i<pos-1 && p;i++){
            q=p;
            p=p->next;
        }

        if(p){
            q->next=p->next;
            x=p->data;
            delete p;
        }


    }

    return x;

}

void Display(struct Node *p){
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main()
{
    int A[]={10,20,30,40,50};
    createNode(A,5);
    Display(first);
    cout << "Deletion of node: " << endl;
    int del = Delete(4);
    cout<<"result: "<<del<<endl;
    Display(first);

    return 0;
}
