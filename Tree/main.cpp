#include <iostream>
#include<stdlib.h>
#include "Queue.h"

using namespace std;

struct Node *root=NULL;

void TreeCreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    cout<<"Enter the root value"<<endl;
    root=(struct Node *)malloc(sizeof(struct Node));
    cin>>root->data;
    root->lchild=NULL;
    root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        cout<<"Enter left child of"<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        cout<<"Enter right child of"<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }

    }


}

void Preorder(struct Node *p)
{
    if(p)
    {
        cout<<p->data<<endl;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }

}

void Inorder(struct Node *p)
{
    if(p)
    {
    Inorder(p->lchild);
    cout<<p->data<<endl;
    Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if(p)
    {
    Postorder(p->lchild);
    Postorder(p->rchild);
    cout<<p->data<<endl;
    }
}

int main()
{
    TreeCreate();
    cout<<"PreOrder"<<endl;
    Preorder(root);
    cout<<"PostOrder"<<endl;
    Postorder(root);
}
