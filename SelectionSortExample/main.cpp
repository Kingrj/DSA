#include <iostream>

using namespace std;

void SelectionSort(int A[], int n){
    int temp=-1,k;
    for(int i=0;i<n;i++){
        for(int j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;

            }
        }
        temp=A[i];
        A[i]=A[k];
        A[k]=temp;

    }
}


void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }

}

int main()
{
    int A[] = {8,6,3,2,5,7,12};
    Display(A,7);
    SelectionSort(A,7);
    cout<<endl<<"Sorted Array: "<<endl;
    Display(A,7);
    return 0;
}
