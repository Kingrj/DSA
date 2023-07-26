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

void create(struct Queue *p)
{
    cout<<"Enter Queue Size"<<endl;
    cin>>p->q_size;
    p->q_front=0;
    p->q_rear=0;
    p->Q=new int[p->q_size];
}

void enqueue(struct Queue *p, int x)
{
    if((p->q_rear+1)%p->q_size==p->q_front)
    {
        cout<<"Queue Full"<<endl;
    }
    else
    {
        p->q_rear=(p->q_rear+1)%p->q_size;
        p->Q[p->q_rear]=x;
    }
}

int dequeue(struct Queue *p)
{
    int x=-1;
    if(p->q_front==p->q_rear)
    {
        cout<<"Queue Empty";
    }
    else
    {
        p->q_front=(p->q_front+1)%p->q_size;
        x=p->Q[p->q_front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i=0;
    for(i=q.q_front+1;i!=q.q_rear+1;i=(i+1)%q.q_size)
    {
        cout<<q.Q[i]<<endl;
    }
}



int main()
{

    struct Queue q;
    create(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    cout<<"Queue Data Before Deletion"<<endl;
    Display(q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    cout<<"Queue Data After Deletion"<<endl;
    Display(q);

    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    cout<<"Queue Data After Insertion"<<endl;
    Display(q);



}
