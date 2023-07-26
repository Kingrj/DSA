#include <iostream>

using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){
    struct Node *temp,*last;
    first=new Node;
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        temp=new Node;
        temp->prev=last;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }

}

int DeleteNode(int pos){
    struct Node *p=first;
    int x=-1;
    if(pos==1){

            first=first->next;
            //If there is only one node then first->next will be null so there will be no prev pointer for that
            //If first is not NULL then only first->prev should set as NULL
            if(first){
                first->prev=NULL;
            }

            x=p->data;
            delete p;
        }

    else{

            for(int i=0;i<pos-1;i++){
                p=p->next;
            }
            p->prev->next=p->next;
            x=p->data;
            if(p->next){
                p->next->prev=p->prev;
            }
            delete p;


    }
    return x;


}

void Display(struct Node *p){
    while(p){
        cout<<p->data;
        p=p->next;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    Display(first);
    cout<<endl<<"Deleted Node: "<<DeleteNode(4)<<endl;
    Display(first);
    return 0;
}
