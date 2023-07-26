#include<iostream>
#include<stdlib.h>

using namespace std;

void InsertHeap(int A[], int index)
{
    int i=index, temp;
    temp=A[i];

    while(i>1 && temp > A[i/2])
    {
       A[i]=A[i/2];
       i=i/2;
    }
    A[i]=temp;
}

int DeleteHeap(int A[], int index)
{
    int val=A[1]; //We always delete root node
    A[1]=A[index];
    int i=1;



    while(i<index)
    {
        int left=A[2*i];
        int right=A[2*i+1];
        int larger=left>right ? 2*i : 2*i+1;
        if(A[i] < A[larger])
        {
            int temp=A[i];
            A[i]=A[larger];
            A[larger]=temp;

        }

        i=larger;


    }

return val;
}
int main()
{
    int H[]={0,10,20,30,25,5,40,35};
    int i;


    for(i=2;i<=7;i++)
    {
        InsertHeap(H,i);

    }

    for(i=1;i<=7;i++){
        cout<<H[i]<<endl;
    }


    int del=DeleteHeap(H,7);
    cout<<"Deleted element is "<<del<<endl;


    for(i=1;i<=7;i++){
        cout<<H[i]<<endl;
    }
}
