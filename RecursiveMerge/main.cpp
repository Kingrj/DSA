#include <iostream>

using namespace std;


void mergeArr(int A[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int B[50];
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            B[k++]=A[i++];
        }
        else
            B[k++]=A[j++];
    }

    for(;i<=mid;i++){
        B[k++]=A[i];
    }
    for(;j<=h;j++){
        B[k++]=A[j];
    }
    for(int i=l;i<=h;i++){
        A[i]=B[i];
    }


}




void RMergeSort(int A[], int l, int h){
    if(l<h){

        int mid = (l+h)/2;
        RMergeSort(A,l,mid);
        RMergeSort(A,mid+1,h);
        mergeArr(A,l,mid,h);

    }


}


void Display(int A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
}

int main()
{
    int A[] = {8,3,7,4,9,2,6,5};
    Display(A,8);
    RMergeSort(A,0,7);
    cout<<"Sorted array"<<endl;
    Display(A,8);

    return 0;
}
