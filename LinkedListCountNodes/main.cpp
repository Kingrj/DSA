#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;

}*first=NULL;

void create(int A[],int n){

    struct Node *last,*temp;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++){
            temp = new Node;
            temp -> data = A[i];
            temp ->next = NULL;
            last ->next = temp;
            last = temp;

    }

}

int countNodes(struct Node *p){
    int count =0;
    while(p){
        count++;
        p=p->next;
    }

    return count;
}


int countNodesRecursive(struct Node *p){
    if(p==0){
        return 0;
    }

    if(p!=NULL){
        return countNodesRecursive(p->next)+1;
    }
}
int main()
{

    int A[] = {3,6,9,12,15,18};
    create(A,6);
    int res = countNodes(first);
    cout<<"Number of nodes: "<<res;

    cout<<endl;

    int resu = countNodesRecursive(first);
    cout<<"Number of nodes (Recursive Count): "<<resu;


    return 0;
}
