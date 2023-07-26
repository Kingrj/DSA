#include <iostream>

using namespace std;

//Create node first
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

    for(int i=1;i<n;i++){
        temp = new Node;
        temp -> data = A[i];
        temp -> next = NULL;
        last -> next = temp;
        last = temp;
    }


}

void RecursiveDisplay(struct Node *p){
    if(p!=NULL){
    cout << p->data<<" ";
    RecursiveDisplay(p->next);
    }
}

void RecursiveReverseDisplay(struct Node *p){

    if(p!=NULL){
        RecursiveReverseDisplay(p->next);
        cout << p->data<<" ";
    }
}
int main()
{
    int A[] = {2,4,6,8,10};
    create(A,5);
    cout<<"Lets print in normal order"<<endl;
    RecursiveDisplay(first);
    cout<<endl;
    cout<<"Lets print in reverse order"<<endl;
    RecursiveReverseDisplay(first);
}
