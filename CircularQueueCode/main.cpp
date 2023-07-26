#include <iostream>

using namespace std;

struct Queue {
    int q_size;
    int frontp;
    int rearp;
    int *Q;

};

void enqueue(struct Queue *q, int x){
    if((q->rearp+1)%q->q_size==q->frontp){
        cout<<"Queue is full"<<endl;
    }
    else{
        q->rearp=(q->rearp+1)%q->q_size;
        q->Q[q->rearp]=x;
    }

}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->frontp==q->rearp){
        cout<<"Queue is empty"<<endl;
    }
    else{
        q->frontp = (q->frontp+1)%q->q_size;
        x=q->Q[q->frontp];

    }
    return x;
}

void Display(struct Queue q){
    int i = q.frontp+1;

    do
    {
        cout<<q.Q[i]<<endl;
        i = (i+1)%q.q_size;
    }while(i!=(q.rearp+1)%q.q_size);

}




int main()
{
    struct Queue q;
    cout<<"Enter the size of queue"<<endl;
    cin>>q.q_size;
    q.frontp=q.rearp=-1;
    q.Q = new int[q.q_size];

    enqueue(&q, 40);
    enqueue(&q, 60);
    enqueue(&q, 70);
    Display(q);

    int data = dequeue(&q);
    cout<<"Data: "<<data<<endl;

    Display(q);

    return 0;
}
