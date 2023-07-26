#include <iostream>
#include <cstring>

using namespace std;

struct Stack {
    int s_size;
    int top;
    char *S;
}s;

void push(struct Stack *st, int value){
    if(st->top==st->s_size-1){
        cout<<"Stack is full"<<endl;
    }
    else {
        st->top++;
        st->S[st->top]=value;
    }

}

int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        x=st->S[st->top];
        st->top--;

    }
    return x;
}

int isEmpty(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    else
        return 0;
}

int isBalanced(char *exp){

    for(int i=0; exp[i]!='\0';i++){
            if(exp[i]=='('){
                push(&s, exp[i]);
            }
            else if(exp[i]==')'){
                if(s.top==-1){
                    return false;
                }
                else{
                    pop(&s);
                }
        }
    }
    return isEmpty(s)?true:false;

}

int main()
{
    char *exp = "(((a+b)*(c-d))";
    s.s_size=strlen(exp);
    s.top=-1;
    s.S=new char[s.s_size];
    bool a = isBalanced(exp);
    if(a==1){
        cout<<"Parenthesis matching"<<endl;
    }
    else{
        cout<<"Parenthesis not matching"<<endl;
    }
}
