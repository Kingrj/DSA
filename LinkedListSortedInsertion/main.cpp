#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){

    struct Node *temp,*last;

    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){

        temp = new Node;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }

}

void SortedInsert(struct Node *p, int value){
    struct Node *q,*tem=NULL;

    tem = new Node;
    tem->data=value;
    tem->next=NULL;

    if(first==NULL){
        first=tem;
    }

    else
    {

        //Case : 1Node: if you want to insert greater value than first node then in that case p will be null and q will point to first node
        while(p && p->data<value){
                q=p;
                p=p->next;
            }
        if(p==first){
            tem->next=first;
            first=tem;
        }
        else{
            tem->next=q->next;
            q->next=tem;

        }

    }

}

void Display(struct Node *p){

    cout<<"Printing linked list"<<endl;

    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }

}

int main()
{
    int A[] = {1,2,3,4,5,9};
    create(A,6);
    Display(first);

    SortedInsert(first,8);
    Display(first);


    return 0;
}
