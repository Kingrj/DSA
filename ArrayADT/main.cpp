#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int a_size;
    int a_length;

};

void Display(struct Array *arr)
{

    int i;
    for(i=0;i<arr->a_length;i++)
    {
        cout<<arr->A[i]<<endl;;
    }
}

void Append(struct Array *arr, int x)
{
    if(arr->a_length<arr->a_size)
    {
        arr->A[arr->a_length++]=x;
    }
}
void Insert(struct Array *arr, int index, int number)
{
    int i;
    for(i=arr->a_length;i>index;i--)
    {
        arr->A[i]=arr->A[i-1];
    }

    arr->A[index]=number;
    arr->a_length = arr->a_length+1;
}

int main()
{
    struct Array arr{{1,2,4,8},10,4};
    cout<<"Before Append"<<endl;
    Display(&arr);
    Append(&arr,16);
    cout<<"After Append"<<endl;
    Display(&arr);
    Insert(&arr,0,20);
    Display(&arr);
}
