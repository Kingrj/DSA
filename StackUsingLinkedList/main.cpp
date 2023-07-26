#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*Top=NULL;


void push(int value){
    struct Node *t;
    t=new Node;
    if(t==NULL){
        cout<<"Stack is full"<<endl;
    }
    else{
        t->data=value;
        t->next=Top;
        Top=t;
        cout<<Top->data<<endl;
    }
}

int pop(){
    int x=-1;
    struct Node *t;
    if(Top==NULL){
       cout<<"Stack is empty"<<endl;
    }
    else{
        t=Top;
        Top=Top->next;
        x = t->data;
        delete t;

    }
    return x;
}

int peek(int pos){

    struct Node *p=Top;
    for(int i=0;p!=NULL && i<pos-1;i++){

        p=p->next;
    }
    if(p!=NULL)
        return p->data;

}

int isEmpty(){
    if(Top==NULL)
        return 1;
    else
        return 0;
}

int stackTop(){
    if(Top==NULL)
        return -1;
    else
        return Top->data;
}

int isFull(){
    struct Node *t = new Node;
    if(t==NULL)
        cout<<"Stack is full"<<endl;

}

void Display(){
    struct Node *p;
    p=Top;

    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }

}
int main()
{

    cout<<"Inserting elements in Stack"<<endl;
    push(5);
    push(10);
    push(15);
    push(20);

    cout<<"Printing Stack"<<endl;
    Display();

    cout<<"Pop:"<<pop()<<endl;

    cout<<"Printing Stack 2:"<<endl;
    cout<<"Peek:"<<peek(2)<<endl;
    Display();


    return 0;
}
