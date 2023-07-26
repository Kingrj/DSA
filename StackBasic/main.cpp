#include<iostream>
#include<stdlib.h>

using namespace std;

struct Stack{
int s_size;
int Top;
int *S;
};

void create(struct Stack *st){

    cout<<"Enter the stack size"<<endl;
    cin>>st->s_size;
    st->S=new int[st->s_size];
    st->Top=-1;
}

void Display(struct Stack st)
{
    int i;
    for(i=st.Top;i>=0;i--)
    {

        cout<<st.S[i]<<endl;
    }

}

void push(struct Stack *st, int x)
{

    if(st->Top==st->s_size-1)
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        st->Top++;
        st->S[st->Top]=x;
    }
}

int pop(struct Stack *st)
{

int x=-1;

    if(st->Top==-1)
    {
        cout<<"Stack Empty"<<endl;
    }
    else
    {

        x=st->S[st->Top--];
    }
    return x;
}

int peek(struct Stack st, int index)
{

    int x=-1;

    if(st.Top-index+1<0){
    cout<<"Invalid Stack Index"<<endl;
    }
    else{
    x=st.S[st.Top-index+1];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if(st.Top==-1)
        return 1;
    else
        return 0;

}

int isFull(struct Stack st)
{

    if(st.Top==st.s_size-1)
        return 1;
    else
        return 0;
}

int stackTop(struct Stack st)
{
    if(!isEmpty)
        return st.S[st.Top];
    return -1;

}

int main(){

struct Stack st;
create(&st);
push(&st,10);
push(&st,20);
push(&st,30);
push(&st,40);
push(&st,50);
Display(st);
int x=isFull(st);
cout<<x;
}
