#include <iostream>

using namespace std;

struct Node {

    struct Node *lchild;
    int data;
    struct Node *rchild;

}*root=NULL;


struct Queue {
    int q_size;
    int front_p;
    int rear_p;
    struct Node **Q;
}q;

void enqueue(struct Queue *q, struct Node *a){
    if((q->rear_p+1)%q->q_size==q->front_p){
        cout<<"Queue is full"<<endl;
    }
    else{
        q->rear_p=(q->rear_p+1)%q->q_size;
        q->Q[q->rear_p]=a;
    }

}


struct Node* dequeue(struct Queue *q){
    struct Node *temp=NULL;
    if(q->front_p==q->rear_p){
        cout<<"Queue is empty"<<endl;
    }
    else{
        q->front_p=(q->front_p+1)%q->q_size;
        temp = q->Q[q->front_p];

    }
    return temp;

}

int isEmpty(struct Queue q){
    if(q.front_p==q.rear_p){
        return 1;
    }
    else
        return 0;

}

void Preorder(struct Node *p){
    if(p){
        cout<<p->data<<endl;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p){
    if(p){

        Inorder(p->lchild);
        cout<<p->data<<endl;
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p){
    if(p){

        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<endl;
    }
}

void create(){
    struct Node *p,*t;
    int x;

    cout<<"Enter the data of root node"<<endl;
    cin>>x;
    //create root node
    root = new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;

    //inserted address of root node in queue
    enqueue(&q,root);

    //loop will run till queue is not empty
    while(!isEmpty(q)){

        //taking out address of node from queue
        p=dequeue(&q);
        cout<<"Enter left child of node"<<endl;
        //Taking input from user
        cin>>x;

        //if input is passed and value is not -1 then perform below steps
        if(x!=-1){

            //Create a node, set value
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;

            //p->lchild will point it to t
            p->lchild=t;

            //insert address of node in queue
            enqueue(&q,t);
        }
        cout<<"Enter right child of node"<<endl;
        cin>>x;

        //if input is passed and value is not -1 then perform below steps
        if(x!=-1){

            //Create a node, set value
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=0;
            p->rchild=t;
            enqueue(&q,t);
        }

    }


}

int main()
{
    cout<<"Program started!"<<endl;
    q.q_size=10;
    q.front_p=q.rear_p=-1;
    q.Q = new Node*[q.q_size];
    cout<<"Calling create function to create tree"<<endl;
    create();
    Preorder(root);
    Postorder(root);

    return 0;
}
