#include<iostream>
#include<stdlib.h>

using namespace std;

struct Queue
{
    int q_size;
    int q_front;
    int q_rear;
    int *Q;

};

void create(struct Queue *q)
{

    cout<<"Enter the Queue size";
    cin>>q->q_size;
    q->q_front=-1;
    q->q_rear=-1;
    q->Q=new int[q->q_size];
}

void enqueue(struct Queue *p, int x)
{
    if(p->q_rear==p->q_size-1)
    {
        cout<<"Queue Is Full"<<endl;
    }
    else
    {
        p->q_rear++;
        p->Q[p->q_rear]=x;
    }


}

int dequeue(struct Queue *p)
{
    int x=-1;
    if(p->q_front==p->q_rear)
    {
        cout<<"Queue Empty"<<endl;
    }
    else
    {
        p->q_front++;
        x=p->Q[p->q_front];

    }
    return x;
}

void Display(struct Queue q)
{
    int i=0;

    for(i=q.q_front+1;i<=q.q_rear;i++)
        cout<<q.Q[i]<<endl;
    }

int main(){
    struct Queue q;
    create(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    Display(q);

    int x1=dequeue(&q);
    cout<<"Deleted:"<<x1<<endl;
    int x2=dequeue(&q);
    cout<<"Deleted:"<<x2<<endl;
    int x3=dequeue(&q);
    cout<<"Deleted:"<<x3<<endl;
    int x4=dequeue(&q);
    cout<<"Deleted:"<<x4<<endl;
    int x5=dequeue(&q);
    Display(q);

    enqueue(&q,50);
    enqueue(&q,60);


}
