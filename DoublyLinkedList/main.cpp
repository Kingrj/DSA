#include <iostream>

using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void createDoubly(int A[], int n){
    struct Node *temp,*last;
    first=new Node;
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;


    for(int i=1; i<n;i++){

        temp = new Node;
        temp->prev=last;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void Display(struct Node *p){
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}

int lengthDoubly(struct Node *p){
    int len=0;
    while(p){
        len=len+1;
        p=p->next;
    }
    return len;
}

int main()
{
    int A[]= {5,10,15,20,25};
    createDoubly(A,5);
    cout<<"Length: "<<lengthDoubly(first)<<endl;
    Display(first);
    return 0;
}
