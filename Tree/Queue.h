#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<iostream>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int qsize;
    int frontp;
    int rearp;
    struct Node **Q;
};

void create(struct Queue *q, int tsize)
{
    q->qsize=tsize;
    q->frontp=q->rearp=0;
    q->Q=(struct Node **)malloc(q->qsize*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if((q->rearp+1)%q->qsize==q->frontp)
    {
        std::cout<<"Queue is full";
    }
    else
    {
        q->rearp=(q->rearp+1)%q->qsize;
        q->Q[q->rearp]=x;
    }

}

struct Node* dequeue(struct Queue *q)
{
    struct Node *x=NULL;

    if(q->rearp==q->frontp)
    {
        std::cout<<"Queue is empty";
    }
    else
    {
        q->frontp=(q->frontp+1)%q->qsize;
        x=q->Q[q->frontp];
    }
    return x;

}

int isEmpty(struct Queue q)
{
    return q.frontp==q.rearp;
}

#endif // QUEUE_H_INCLUDED
