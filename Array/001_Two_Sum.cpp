/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Bruteforce method.
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans(2, 0);
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}

// sort method. (from apna college) But changes indices
vector<int> twoSumS(vector<int> &nums, int target)
{
    vector<int> ans(2, 0);
    int l = 0;
    int r = nums.size() -1;

    sort(nums.begin(), nums.end());

    while(l < r){
        int sum = nums[l] + nums[r];
        if (sum == target)
        {
            ans[0] = l;
            ans[1] = r;
            return ans;
        }
        else if(sum > target){r--;}
        else{l++;}
        
    }
    return ans;
}

int main()
{
    vector<int> input = {13, 11, 7, 23, 2};
    vector<int> ans =  twoSumS(input, 9);
    cout << ans[0]<<", "<<ans[1];

    return 0;
}