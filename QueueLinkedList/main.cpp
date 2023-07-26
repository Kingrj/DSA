#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*frontp=NULL,*rearp=NULL;


void enqueue(int x){
    struct Node *t = new Node;
    if(t==NULL){
        cout<<"Queue is full"<<endl;
    }
    else{
        t->data=x;
        t->next=NULL;
        if(frontp==NULL){
            frontp=rearp=t;
        }
        else{
            rearp->next=t;
            rearp = t;


        }
    }

}

int dequeue(){
    int x=-1;
    struct Node *p;
    if(frontp==NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
            p=frontp;
            frontp = frontp->next;
            x = p->data;
            delete p;

    }
    return x;

}

void Display(){
    struct Node *p;
    p=frontp;

    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}




int main()
{
    enqueue(100);
    enqueue(200);
    enqueue(300);

    Display();

    int data = dequeue();
    cout<<"Data: "<<data<<endl;

    Display();

    return 0;
}
