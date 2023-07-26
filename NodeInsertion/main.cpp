#include <iostream>

using namespace std;


struct Node{
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n){
    struct Node *temp,*last;

    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=0;i<n;i++){
        temp=new Node;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void insertNode(int pos, int value){
    if(pos==0){
        struct Node *t = new Node;
        t->data=value;
        t->next=first;
        first=t;
    }

    else if(pos>0){

        struct Node *p;
        p=first;

        for(int i=0;i<pos-1 && p;i++){
            p=p->next;
        }

        if(p){

            struct Node *t = new Node;
            t->data=value;
            t->next=p->next;
            p->next=t;

        }


    }


}

void Display(struct Node *p){
    while(p){

        cout<<p->data<<endl;
        p=p->next;
    }

}

int main()
{

    int A[] = {2,4,6,8,10};
    create(A,5);
    insertNode(0,12);
    insertNode(7,18);
    Display(first);

    return 0;
}
