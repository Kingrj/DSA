#include <iostream>

using namespace std;

int maximum(int A[], int n){
    int maximumVal=0;
    for(int i=0;i<n;i++){
        if(A[i]>maximumVal){
            maximumVal=A[i];
        }

    }
    return maximumVal;


}

void CountSort(int A[], int n){

    int maxi = maximum(A,n);
    int Count[maxi+1]={0};

    for(int i=0;i<n;i++){
        Count[A[i]]=Count[A[i]]+1;
    }

    int i=0,j=0;
    while(i<=maxi){
        if(Count[i]>0){
            A[j++]=i;
            Count[i]--;
        }
        else
            i++;
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
    CountSort(A,8);
    cout<<"Sorted array: "<<endl;
    Display(A,8);
    return 0;
}
