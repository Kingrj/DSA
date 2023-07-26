#include<bits/stdc++.h>

using namespace std;

void setMatrixZero(vector<vector<int>> & matrix)
{
    int x=1;
    int y=1;

    int row=matrix.size();
    int column=matrix[0].size();


    for(int i=0;i<row;i++)
    {
        if(matrix[i][0]==0){
            y=0;
        }
    }

    for(int j=0;j<column;j++)
    {
        if(matrix[0][j]==0){
            x=0;
        }
    }

    for(int i=1;i<row;i++){
        for(int j=1;j<column;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    for(int j=1;j<column;j++)
    {
        if(matrix[0][j]==0)
        {
            for(int i=1;i<row;i++)
            matrix[i][j]=0;
        }
    }

    for(int i=1;i<column;i++)
    {
        if(matrix[i][0]==0)
        {
            for(int j=1;j<column;j++)
            matrix[i][j]=0;
        }
    }
    if(y==0){
        for(int i=0;i<row;i++)
        {
            matrix[i][0]=0;
        }
    }

    if(x==0){
        for(int j=1;j<column;j++)
        {
            matrix[0][j]=0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix;
    matrix = {{1,1,1},{1,0,1},{1,1,1}};

    setMatrixZero(matrix);

    int row=matrix.size();
    int column=matrix[0].size();

    for(int i=0;i<row;i++){

        for (int j=0;j<column;j++)
        {
            cout<< matrix[i][j];
        }
    cout<<endl;
    }

}
