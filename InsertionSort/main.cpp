#include <iostream>

using namespace std;

//Time complexity - O(n^2)
//Time complexity - O(n) - Sorted array
//Adaptive - takes O(n) for sorted array
//Stable - Order is preserved
void InsertionSort(int A[], int n){
    int i=0,j=0;
    for(i=0;i<n-1;i++){

        int temp=A[i+1];

        for(j=i;j>-1 && A[j]>temp;j--){
            A[j+1]=A[j];
        }
        A[j+1]=temp;

    }

}

void DisplaySorted(int A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }

}

int main()
{
    int A[]={9,8,7,6,5};
    DisplaySorted(A,5);
    InsertionSort(A,5);
    cout<<"Sorted List"<<endl;
    DisplaySorted(A,5);
    return 0;
}
