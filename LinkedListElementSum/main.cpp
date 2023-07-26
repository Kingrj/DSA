#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){
    struct Node *temp,*last;

    first = new Node;
    first -> data = A[0];
    first -> next = NULL;

    last = first;

    for(int i =1 ; i<n; i++){

        temp = new Node;
        temp -> data = A[i];
        temp -> next = NULL;
        last -> next = temp;
        last = temp;
    }

}

int sumLoop(struct Node *p){
    int sum =0;
    while(p){

        sum = sum + p-> data;
        p=p->next;
    }

    return sum;

}

int sumRecursive(struct Node *p){
    if(p==0){
        return 0;
    }

    else {
        return sumRecursive(p->next)+p->data;
    }
}

int main()
{
    int A[] = {20,10,30,15,35};
    create(A,5);
    int sumResult = sumLoop(first);
    cout<<"Sum: " <<sumResult<<endl;

    int sumResult2 = sumRecursive(first);
    cout<<"Recursive Sum: " <<sumResult2<<endl;
    return 0;
}
