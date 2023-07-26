#include <iostream>

using namespace std;


struct Node{

    struct Node *lchild;
    int data;
    struct Node *rchild;

}*root=NULL;


struct Queue{
    int qsize;
    int frontp;
    int rearp;
    struct Node **Q;
}q;

void enqueue(struct Queue *q, struct Node *p){
    if((q->rearp+1)%q->qsize==q->frontp){
        cout<<"Queue is full"<<endl;
    }
    else{
        q->rearp=(q->rearp+1)%q->qsize;
        q->Q[q->rearp]=p;
    }

}

struct Node* dequeue(struct Queue *q){
    struct Node *temp=NULL;
    if(q->rearp==q->frontp){
        cout<<"Queue is empty"<<endl;
    }
    else{
        q->frontp=(q->frontp+1)%q->qsize;
        temp=q->Q[q->frontp];
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


void createTree(){
    int x;
    struct Node *p,*t;

    cout<<"Enter root node"<<endl;
    cin>>x;

    root = new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p = dequeue(&q);
        cout<<"Enter left child of: "<<p->data<<endl;
        cin>>x;

        if(x!=-1){
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild = t;
            enqueue(&q,t);

        }

        cout<<"Enter right child of: "<<p->data<<endl;
        cin>>x;

        if(x!=-1){
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild = t;
            enqueue(&q,t);

        }
    }
}

void LevelOrderTraversal(struct Node *r){
    struct Node *p=NULL;
    if(!root){
        cout <<"There's no node"<<endl;
    }
    else{
        cout<<r->data<<endl;
        enqueue(&q,r);


        while(!isEmpty(q)){
            p=dequeue(&q);
            if(p->lchild){
                cout<<p->lchild->data<<endl;
                enqueue(&q,p->lchild);
            }
            if(p->rchild){
                cout<<p->rchild->data<<endl;
                enqueue(&q,p->rchild);
            }

        }
    }

}

int main()
{
    q.qsize=10;
    q.frontp=q.rearp=-1;
    q.Q=new Node* [q.qsize];
    createTree();
    LevelOrderTraversal(root);
    return 0;
}
