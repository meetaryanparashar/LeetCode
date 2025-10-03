/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

#include <iostream>
#include <vector>
using namespace std;

// Bruteforce method (O^3)-> not accepeted by leetcode.
int maxSubArrayBF1(vector<int> &nums)
{
    int maxSum = INT16_MIN;
    int size = nums.size();

    for (int st = 0; st < size; st++)
    {
        for (int end = st; end < size; end++)
        {
            int sum = 0;
            for (int idx = st; idx <= end; idx++)
            {
                // sum of subarray
                sum = sum + nums[idx];
            }
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

// Bruteforce method (O^2) -> still time limit exceeded.
int maxSubArrayBF2(vector<int> &nums)
{
    int maxSum = INT16_MIN;
    int size = nums.size();

    for (int st = 0; st < size; st++)
    {
        int sum = 0;
        for (int end = st; end < size; end++)
        {
            sum = sum + nums[end];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
// Kadane's Algorithm
int maxSubArray(vector<int> &nums)
{
    int size = nums.size();

    int currSum = 0;
    int maxSum = INT16_MIN;

    for (int idx = 0; idx < size; idx++)
    {
        currSum = currSum + nums[idx];
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    // vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> input = {5, 4, -1, 7, 8};
    cout << maxSubArray(input);
    return 0;
}