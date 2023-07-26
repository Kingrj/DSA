#include<iostream>
using namespace std;

int main()
{

    int *P=new int[5];
    P[0]=5;
    P[1]=10;
    P[2]=15;
    P[3]=20;
    P[4]=25;
    int *Q=new int[10];
    int i;
    for(i=0;i<5;i++)
    {

        Q[i]=P[i];
    }
    delete[] P;
    P=Q;
    Q=NULL;


    cout<<P[3];

}
