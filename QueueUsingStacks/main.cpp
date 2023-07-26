#include <iostream>

using namespace std;

struct Stack {
    int top;
    int s_size;
    int *S;
}s1,s2;


void push(struct Stack *s, int x){
    s->top++;
    s->S[s->top]=x;

}

int pop(struct Stack *s){
    int x1=-1;
    x1 = s->S[s->top];
    s->top--;
    return x1;

}

void enqueue(int x){
    struct Stack s = s1;
    if(s.top==s.s_size-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        push(&s1,x);

    }

}

int isEmpty(struct Stack s){
    if(s.top==-1){
        return 1;
    }
    else{
        return 0;
    }

}

int dequeue(){
    int x =-1;
    if(isEmpty(s2)){
        if(isEmpty(s1)){
            cout<<"Queue is empty"<<endl;
            return x;
        }
        else{
            while(!isEmpty(s1)){
                push(&s2,pop(&s1));
                }
        }
      }
    return pop(&s2);
}

void Display(){
    if(s2.top==-1){
        cout<<"Queue Empty"<<endl;
    }
    cout<<"Queue: "<<endl;
    for(int i=s2.top; i>-1;i--){
        cout<<s2.S[i]<<endl;
    }

}






int main()
{
    s1.s_size=s2.s_size=6;
    s1.top=s2.top=-1;
    s1.S = new int[s1.s_size];
    s2.S = new int[s2.s_size];

    enqueue(10);
    enqueue(20);
    enqueue(30);

    Display();

    int data1=dequeue();
    cout<<"First: "<<data1<<endl;
    Display();
    return 0;
}
