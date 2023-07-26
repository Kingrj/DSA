#include <iostream>

using namespace std;


//By nature it is not adaptive but we can make it using flag
//It is stable i.e. sorting order is preserved
void BubbleSortAdaptive(int A[], int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-1-i;j++){
            int k=j+1,temp;
            if(A[j]>A[k]){
                temp=A[j];
                A[j]=A[k];
                A[k]=temp;
                flag=1;

            }

        }
        if(flag==0){
            break;
        }

    }

}

void DisplaySorted(int A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }

}

int main()
{
    int A[]={9,8,6,7,2};
    DisplaySorted(A,5);
    BubbleSortAdaptive(A,5);
    cout<<"Sorted List"<<endl;
    DisplaySorted(A,5);

    return 0;
}
