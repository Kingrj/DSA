#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{

    int A[3][4]={1,2,3,4,5,6,7,8,9,10,11,12}; // WILL BE CREATED IN STACK SPACE

    int *p[3]; // POINTER ARRAY IN STACK AND ARRAY IN HEAP
    p[0]=new int[4];
    p[1]=new int[4];
    p[2]=new int[4];

    int **Q; // DOUBLE POINTER IN STACK AND OTHER MEMORY IN HEAP
    Q=new int*[3];
    Q[0]=new int[4];
    Q[1]=new int[4];
    Q[2]=new int[4];

    Q[0][0]=1;
    Q[0][1]=2;
    Q[0][2]=3;
    Q[0][3]=4;
    Q[1][0]=1;
    Q[1][1]=2;
    Q[1][2]=3;
    Q[1][3]=4;
    Q[2][0]=1;
    Q[2][1]=2;
    Q[2][2]=3;
    Q[2][3]=4;

    int i,j;

    for(i=0;i<3;i++)
    {

        for(j=0;j<4;j++)
        {
            cout<<Q[i][j]<<endl;
        }

    }
}
