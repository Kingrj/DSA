#include <iostream>
#include <cstring>
using namespace std;

struct Stack {
    int s_size;
    int top;
    char *S;
};


void push(struct Stack *s, char x){
    if(s->top==s->s_size-1){
        cout<<"Stack is full"<<endl;
    }
    else{
        s->top++;
        s->S[s->top]=x;
    }
}

char pop(struct Stack *s){
    char x;
    if(s->top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        x = s->S[s->top];
        s->top--;
    }
    return x;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    else
        return 1;
}

int Pre(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else
        return 0;

}

int isEmpty(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    else
        return 0;
}

char stackTop(struct Stack st){
    if(st.top){
        return st.S[st.top];
    }

}

char *conversion(char *infix){

    char *postfix;
    postfix = new char[strlen(infix)+1];

    struct Stack st;
    cout<<"Enter size of stack"<<endl;
    cin>>st.s_size;
    st.top=-1;
    st.S = new char[st.s_size];
    push(&st,' ');
    int i=0,j=0;

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
                postfix[j++]=infix[i++];

        }
        else{
            if(Pre(infix[i])>Pre(stackTop(st))){
                    push(&st,infix[i++]);


            }
            else{

                postfix[j++] = pop(&st);
            }

        }


    }

    while(!isEmpty(st)){
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';
    return postfix;

}



int main()
{
    char *infix = "a+b*c";
    char *postfix;

    char *res = conversion(infix);
    cout<<res<<endl;
    return 0;
}
