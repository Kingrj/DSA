#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head=NULL;

void create(int A[], int n){
    struct Node *temp,*last;

    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(int i=1;i<n;i++){

        temp=new Node;
        temp->data=A[i];
        //temp->next=Head; -- This will also work
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }

}

void Display(struct Node *p){
    cout<<"Display: "<<endl;
    do{
        cout<<p->data<<endl;
        p=p->next;
    }while(p!=Head);

}

void RDisplay(struct Node *p){
    static int flag=0;
    if(p!=Head || flag==0){
        flag=1;
        cout<<p->data<<endl;
        RDisplay(p->next);
    }
    flag=0;
}

int main()
{
    int A[]={2,4,6,8,10};
    create(A,5);
    Display(Head);
    cout<<"Recursive Display: "<<endl;
    RDisplay(Head);
    return 0;
}
