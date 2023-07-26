#include <iostream>

using namespace std;

struct Node {

    struct Node *lchild;
    int data;
    struct Node *rchild;

}*root=NULL;

struct Queue{
    int q_size;
    int frontp;
    int rearp;
    struct Node **Q;
}q;

void enqueue(struct Queue *q, struct Node *a){
    if((q->rearp+1)%q->q_size==q->frontp){
        cout<<"Queue is full"<<endl;
    }
    else{
        q->rearp=(q->rearp+1)%q->q_size;
        q->Q[q->rearp]=a;
    }
}

struct Node* dequeue(struct Queue *q){
    struct Node *temp=NULL;
    if(q->frontp==q->rearp){
        cout<<"Queue is empty"<<endl;

    }
    else{
        q->frontp=(q->frontp+1)%q->q_size;
        temp= q->Q[q->frontp];
    }
    return temp;
}

int isEmpty(struct Queue q){
    if(q.rearp==q.frontp){
        return 1;
    }
    else{
        return 0;
    }
}

void create(){
    struct Node *t,*p;
    int x;

    cout<<"Enter data for root node"<<endl;
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;

    enqueue(&q,root);

    while(!isEmpty(q)){
        p=dequeue(&q);
        cout<<"Enter left child of node"<<endl;
        cin>>x;

        if(x!=-1){
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;

            enqueue(&q,t);
        }

        cout<<"Enter right child of node"<<endl;
        cin>>x;

        if(x!=-1){
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;

            enqueue(&q,t);
        }

    }
}

struct Stack{
    int ssize;
    int top;
    struct Node **S;
}st;

int isEmptyStack(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Stack *s,struct Node *t){
    if(s->top==s->ssize-1){
        cout<<"Stack is full"<<endl;
    }
    else{
        s->top++;
        s->S[s->top]=t;
    }
}

struct Node* pop(struct Stack *s){
    struct Node *temp=NULL;
    if(s->top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        temp=s->S[s->top];
        s->top--;

    }
    return temp;
}

void Preorder(struct Node *t){
    while(t!=NULL || !isEmptyStack(st)){
        if(t!=NULL){
            cout<<t->data<<endl;
            push(&st,t);
            t=t->lchild;
        }
        else{
            t=pop(&st);
            t=t->rchild;

        }
    }
}

int main()
{
    q.q_size=20;
    q.frontp=q.rearp=-1;
    q.Q = new Node*[q.q_size];
    st.ssize=20;
    st.top=-1;
    st.S = new Node*[st.ssize];
    create();
    Preorder(root);
    return 0;
}
