#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n){
    struct Node *temp, *last;

    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;


    for(int i=1;i<n;i++){
            temp = new Node;
            temp->data=A[i];
            temp->next=NULL;
            last->next=temp;
            last=temp;
    }

}

//Linear search
struct Node* LSearch(struct Node *p, int key){

    while(p){
        if(p->data==key){
            return p;
        }
        p=p->next;
    }

}

//Recursive Linear Search
struct Node* RSearch(struct Node *p, int key){
    if(p==NULL){
        return NULL;
    }
    else {
        if(p->data==key){
            return p;
        }
        RSearch(p->next,key);
    }

}

//Improve linear searching

struct Node* LSearchImp(struct Node *p, int key){

    struct Node *q=NULL;

    while(p){
        if(p->data==key){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;

    }

}

void DisplayLinked(struct Node *p){
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}

int main()
{
    int A[]={4,8,12,16,20};
    create(A,5);

    DisplayLinked(first);

    struct Node *p1 = LSearch(first,10);
    struct Node *p2 = LSearchImp(first,12);

    if(p1){
        cout<<"Key is found: Linear Search"<<endl;
    }
    else{
        cout<<"Key is not found: Linear Search"<<endl;
    }

    if(p2){
        cout<<"Key is found: Improved searching"<<endl;
    }
    else{
        cout<<"Key is not found: Improved searching"<<endl;
    }

    DisplayLinked(first);

    return 0;
}
