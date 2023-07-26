#include <iostream>

using namespace std;

struct Node {

    int data;
    Node *next;
}*first=NULL;

void create (int A[], int n){


    //Creating pointers of Node type
    struct Node *last,*temp;

    //Creating first node -> [data,*next]
    first = new Node;
    first -> data =A[0];
    first -> next = NULL;

    //Last node is first node - because there's one node only
    last = first;

    //Multiple node creation and pointing by the previous node
    for (int i = 1; i<n; i++) {

            temp = new Node;
            temp -> data = A[i];
            temp -> next = NULL;
            last -> next = temp;
            last = temp;

    }


}

void Display(struct Node *p){


    //To traverse through Linked list
    while(p){
        cout<< p->data <<endl;
        p=p->next;
    }
}

int main()
{



    int A[5] = {1,2,3,4,5};

    create (A,5);

    Display(first);


    return 0;
}
