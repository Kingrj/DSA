#include <iostream>

using namespace std;




void mergeArray(int A[],int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int B[h+1];
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }

    }

    for(;i<=mid;i++){
        B[k++]=A[i];
    }
    for(;j<=h;j++){
        B[k++]=A[j];
    }

    for(i=l;i<=h;i++){
        A[i]=B[i];
    }

}

//O(n*logn)
void IMergeSort(int A[], int n){
    int p;

    for(p=2;p<=n;p=p*2){

        for(int i=0;i+p-1<n;i=i+p){

            int l=i;
            int h=i+p-1;
            int mid=(l+h)/2;

            mergeArray(A,l,mid,h);
        }
    }

    if(p/2<n){
        mergeArray(A,0,p/2-1,n-1);
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
    IMergeSort(A,8);
    cout<<"Sorted array"<<endl;
    Display(A,8);
    return 0;
}
