#include <bits/stdc++.h>

using namespace std;



class Solution {

private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int marker[]){

    if(ds.size()== nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<nums.size();i++){

        if(!marker[i]){

            ds.push_back(nums[i]);
            marker[i]=1;

            recurPermute(ds, nums, ans, marker);
            marker[i]=0;
            ds.pop_back();
        }
    }



    }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        //initialize with 0
        int marker[nums.size()]={0};
        recurPermute(ds, nums, ans, marker);
        return ans;

    }


};

int main()
{
    int nums[3]={1,2,3};

    Solution sol;
    vector<int> v{1,2,3};
    vector<vector<int>> sum = sol.permute(v);

    cout<<"Permutations : " << endl;

    for(auto vctr:sum){
        for(auto vec:vctr){
            cout<<vec<<" ";
        }
        cout<<endl;
    }

}
