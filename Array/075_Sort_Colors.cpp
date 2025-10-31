/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    vector<int> count(3, 0);
    for (int item : nums)
    {
        if (item == 0)
        {
            count[0]++;
        }
        else if (item == 1)
        {
            count[1]++;
        }
        else
        {
            count[2]++;
        }
        int idx = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < count[i]; j++)
            {
                nums[idx] = i;
                idx++;
            }
        }
    }
}
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (int item : nums)
    {cout << item << " ";}

    return 0;
}