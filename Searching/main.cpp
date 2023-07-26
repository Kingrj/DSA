//LINEAR SEARCH WITH TRANSPOSITION AND MOVE TO FRONT - CHANGE SWAP METHOD ONLY

#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int length;
    int asize;
};

int linSearch(struct Array arr, int  key)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]==key)
        {

            cout<<"Search successful"<<endl;
            return i;
        }

    }
    return -1;
}

void tswap(struct Array *arr, int stat)
{

        int temp;
        temp=arr->A[stat-1];
        arr->A[stat-1]=arr->A[stat];
        arr->A[stat]=temp;
}

void mfswap(struct Array *arr, int stat)
{

        int temp;
        temp=arr->A[0];
        arr->A[0]=arr->A[stat];
        arr->A[stat]=temp;
}

int main()
{
    int i;
    struct Array arr={{2,4,6,8,10},5,10};

    int stat=linSearch(arr,10);
    if(stat!=-1)
    {
       mfswap(&arr,stat);
    }
    for(i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<endl;
    }


}
