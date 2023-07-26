#include <iostream>

using namespace std;


int PartitionFun(int A[],int l,int h){
    int pivot = A[l];
    int i=l;int j=h;
    int temp;

    do{
        do{i++;} while(A[i]<=pivot);
        do{j--;} while(A[j]>pivot);
        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    temp=A[l];
    A[l]=A[j];
    A[j]=temp;
    return j;

}


void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j=PartitionFun(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }

}

void Display(int A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";

    }
    cout<<endl;
}

int main()
{
    int A[] = {50,70,60,90,40,80,10,20,30,INT32_MAX};

    Display(A,9);

    QuickSort(A,0,9);

    Display(A,9);


    return 0;
}
