#include <iostream>
#include<limits.h>

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

    for(int i=1;i<n;i++){
        temp = new Node;
        temp -> data= A[i];
        temp -> next = NULL;
        last -> next = temp;
        last = temp;
    }


}

int maxValue(struct Node *p){
    int maxi = INT_MIN;
    while(p){
        if(p->data > maxi){
            maxi=p->data;
        }
        p=p->next;
    }
    return maxi;
}

int maxValueRecursive(struct Node *p){
    int x;
    if(p==0){
        return INT_MIN;
    }
    else{
        x = maxValueRecursive(p->next);
        if(x > p->data){
            return x;
        }
        else{
            return p->data;
        }
    }
}

int main()
{
    int A[] = {10,12,13,14,16,22};
    cout<<"Creating linked list"<<endl;

    create(A,6);

    cout<<"Calling maxValue function"<<endl;
    int maximum = maxValue(first);
    cout<< "Maximum: "<< maximum<<endl; // Output - 22

    int maximumVal = maxValueRecursive(first);
    cout<< "Maximum Value: "<< maximumVal; // Output - 22



    return 0;
}
