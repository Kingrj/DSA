#include <iostream>

using namespace std;

struct Stack {
    int a_size;
    int Top;
    int *S;
};

int isEmpty(struct Stack st){
    if(st.Top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st){
    if(st.Top==st.a_size-1)
        return 1;
    else
        return 0;
}

void push(struct Stack *st, int elem){
    //Check whether stack is full or not
    if(st->Top==st->a_size-1){
        cout<<"Stack overflow"<<endl;
    }
    else{
        st->Top++;
        st->S[st->Top]=elem;
    }

}

int pop(struct Stack *st){
    int x=-1;
    //Check whether stack is empty or not
    if(st->Top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        x=st->S[st->Top];
        st->Top--;
    }
    return x;

}

int peek(struct Stack st, int pos){
    int x=-1;
    //Check whether stack is empty or not
    if(st.Top-pos+1<0)
        cout<<"Position is invalid"<<endl;
    else{
        x = st.S[st.Top-pos+1];
    }
    return x;
}

int stackTop(struct Stack st){
    if(st.Top==-1){
        return -1;
    }
    else{
        return st.S[st.Top];
    }

}

void printStack(struct Stack st){
    while(st.Top!=-1){
        cout<<st.S[st.Top]<<endl;
        st.Top--;
    }
}

int main()
{
    struct Stack st;
    cout<<"Enter the size of stack"<<endl;
    cin>>st.a_size;
    st.Top=-1;
    st.S= new int[st.a_size];
    cout<<"Empty: "<<isEmpty(st)<<endl;
    cout<<"Full: "<<isFull(st)<<endl;
    isFull(st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    printStack(st);
    int data=pop(&st);
    cout<<"After popping"<<endl;
    printStack(st);
    int res=peek(st,3);
    cout<<"Peek for position 3: "<<res<<endl;
    cout<<"Deleted : "<<data<<endl;
    return 0;
}
