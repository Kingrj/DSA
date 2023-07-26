#include <bits/stdc++.h>
#include<iostream>

using namespace std;

//Brute force approach

vector<int> twoSum(vector<int> &nums, int target){
    vector<int> res;
    for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                    if(i==j){
                        continue;
                    }
                    if(nums[i]+nums[j]==target){
                        res.push_back(i);
                        res.push_back(j);
                        return res;

                    }

                }
            }



}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);


    vector<int> result;

    result=twoSum(nums,6);
    for(auto numb: result){
            cout<<numb<<" ";

    }


    return 0;
}
