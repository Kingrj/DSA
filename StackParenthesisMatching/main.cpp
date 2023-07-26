#include<iostream>
#include<stdlib.h>

using namespace std;

struct Stack
{
    int s_size;
    int top;
    char *S;
};

void create(struct Stack *st)
{
    cout<<"Enter the size of stack"<<endl;
    cin>>st->s_size;
    st->top=-1;
    st->S=new char[st->s_size];

}

void push(struct Stack *st, char c)
{
    if(st->top==st->s_size-1)
        cout<<"Stack is full"<<endl;
    else
        st->top++;
        st->S[st->top]=c;
}

char pop(struct Stack *st)
{
    char c='N';
    if(st->top==-1)
        cout<<"Stack is empty"<<endl;
    else
       c=st->S[st->top];
       st->top--;
    return c;
}

void Display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        cout<<st.S[i]<<endl;
    }
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st,'(');
    push(&st,'(');
    cout<<"Displaying stack after pushing"<<endl;
    Display(st);
    char a=pop(&st);
    cout<<"Displaying stack after popping"<<endl;
    Display(st);
    int b=isEmpty(st);
    if(b==1){
        cout<<"Parenthesis Matched"<<endl;
    }
    else
        cout<<"Parenthesis Not Matched"<<endl;
}
