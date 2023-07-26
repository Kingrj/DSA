#include <iostream>

using namespace std;

//Time complexity - O(n^2)
void BubbleSortAlgo(int A[], int n){

    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-1-i;j++){
            int k=j+1,temp;
            if(A[j]>A[k]){
                temp = A[j];
                A[j]=A[k];
                A[k]=temp;
            }
        }
    }


}

void SortedDisplay(int A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }

}

int main()
{
    int A[]={9,7,4,5,8};
    SortedDisplay(A,5);
    BubbleSortAlgo(A,5);
    cout<<"Sorted list"<<endl;
    SortedDisplay(A,5);
    return 0;
}
