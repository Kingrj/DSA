#include <iostream>

using namespace std;

struct Node {
    char data;
    struct Node *next;
}*top=NULL;

void push(int val){
    struct Node *t;
    t= new Node;
    if(t==NULL){
        cout<<"Stack is full"<<endl;
    }
    else{
        t->data=val;
        t->next=top;
        top=t;
    }

}

int pop(struct Node *p){
    int x=-1;

    if(top==NULL){
        cout<<"Stack is empty"<<endl;
    }
    else{
        top=top->next;
        x=p->data;
        delete p;

    }
    return x;
}

int isEmpty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}

int isBalanced(char *exp){
    for(int i=0;exp[i]!='\0';i++){
            if(exp[i]=='('){
                push(exp[i]);
            }
            else if(exp[i]==')'){
                if(top==NULL){
                    return false;
                }
                pop(top);
        }
    }

    return isEmpty()?true:false;
}


int main()
{
    char *exp="((a+b)*(c-d))";
    bool a = isBalanced(exp);
    cout<<"Matching: "<<a;

    return 0;

}
