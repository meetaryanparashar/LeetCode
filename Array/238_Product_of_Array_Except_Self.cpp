/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include <iostream>
#include <vector>
using namespace std;

// Bruteforce approach

vector<int> productExceptSelfBF(vector<int> &nums)
{
    // Bruteforce
    vector<int> output(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        int product = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        output[i] = product;
    }
    return output;
}

// optimised with extra space
vector<int> productExceptSelfXS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> output(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    for (int i = 1; i < n; i++)
    {
        prefix[i] *= nums[i - 1]*prefix[i-1];
    }

    
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] *= nums[i + 1]* suffix[i+1];
    }

    
    for (int i = 0; i < n; i++)
    {
        output[i] = prefix[i] * suffix[i];
    }
    return output;
}

// optimised without extra space
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> output(n, 1);
    
    for (int i = 1; i < n; i++)
    {
        output[i] = nums[i-1] * output[i-1];
    }

    int currProduct = 1;
    for (int i = n-2; i >= 0; i--)
    {
        output[i] *= nums[i+1] * currProduct;
        currProduct *= nums[i+1]; 
    }
    return output;
}
int main()
{

    vector<int> input = {1,2,3,4,5};
    vector<int> ans = productExceptSelf(input);


    for ( int item:ans){
        cout << item << " ";
    }
    return 0;
}