//BINARY SEARCH THROUGH LOOP AND RECURSION - CHANGE FUNCTION NAME ONLY

#include<iostream>
using namespace std;


struct Array
{

    int A[10];
    int length;
    int asize;
};

int lbinSearch(struct Array arr, int key)
{
    int l=0;
    int h=arr.length;


    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr.A[mid]==key)
        {
            return mid;
        }
        else if(arr.A[mid]>key)
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;

        }
    }
    return -1;
}

int rbinSearch(struct Array arr, int key,int l,int h)
{
    if(l<=h)
    {
       int mid=(l+h)/2;
       if(arr.A[mid]==key)
       {
           return mid;
       }

        else if(arr.A[mid]>key)
        {
            rbinSearch(arr,key,l,mid-1);
        }
        else
        {
            rbinSearch(arr,key,mid+1,h);
        }
    }
    else{return -1;}


}

int main()
{
    struct Array arr={{3,6,9,12,15,18},6,10};

    int stat=rbinSearch(arr,18,0,arr.length);
    if(stat!=-1)
    {
       cout<<"Element found at "<<stat;
       return 0;
    }
    cout<<stat;





}
