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

int countNode(struct Node *p){
    int x,y;
    if(p){
        x=countNode(p->lchild);
        y=countNode(p->rchild);
        return x+y+1;
    }
    else{
        return 0;
    }

}

int treeHeight(struct Node *p){
    int x,y;
    if(p){
        x=treeHeight(p->lchild);
        y=treeHeight(p->rchild);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
    }
    else{
        return 0;
    }
}

int sumNodes(struct Node *p){
    int x,y;
    if(p){
        x=sumNodes(p->lchild);
        y=sumNodes(p->rchild);
        return x+y+p->data;
    }
    else{
        return 0;
    }

}

int main()
{
    q.qsize=10;
    q.frontp=q.rearp=-1;
    q.Q=new Node*[q.qsize];
    createTree();
    int nodes= countNode(root);
    int sum = sumNodes(root);
    int height = treeHeight(root);

    cout<<"Node: "<<nodes<<" Sum: "<<sum<<" Height: "<<height<<endl;

    return 0;
}
