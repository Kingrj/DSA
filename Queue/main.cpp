#include <iostream>

using namespace std;

struct Queue {
    int q_size;
    int frontp;
    int rearp;
    int *Q;

};

void enqueue(struct Queue *q, int x){
    if(q->rearp==q->q_size-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        q->rearp++;
        q->Q[q->rearp]=x;
    }

}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->frontp==q->rearp){
        cout<<"Queue is empty"<<endl;
    }
    else{
        q->frontp++;
        x = q->Q[q->frontp];
    }
    return x;



}

void Display(struct Queue q){

    for(int i=q.frontp+1;i<=q.rearp;i++){
            cout<<q.Q[i]<<endl;

    }
}

int main()
{

    struct Queue q;
    cout<<"Enter the size of queue"<<endl;
    cin>>q.q_size;
    q.frontp=q.rearp=-1;
    q.Q = new int[q.q_size];

    enqueue(&q,10);
    enqueue(&q,20);
    cout<<"Queue after insertion: "<<endl;
    Display(q);

    int x=dequeue(&q);
    cout<<"Queue after deletion: "<<endl;
    Display(q);
    cout<<"Deleted: "<<x<<endl;


    return 0;
}
