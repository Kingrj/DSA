#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> getPascals(int numRows)
{
    vector<vector<int>> arr;

    for(int i=0;i<numRows;i++)
    {
        vector<int> v(i+1,1);

        for(int j=1;j<i;j++)
        {
            v[j]=arr[i-1][j-1]+arr[i-1][j];
        }
        arr.push_back(v);
    }
return arr;
}

int main()
{

    //Time complexity O(N^2)
    int n;
    cout<<"N: ";
    cin>>n;

    vector<vector<int>> vec;
    vec = getPascals(n);

    for(auto vctr: vec){
        for (auto it: vctr){
            cout<<it<<" ";
        }
        cout<<endl;
    }

}
