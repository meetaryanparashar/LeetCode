/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

#include <iostream>
#include <vector>

using namespace std;

// My first approach ------- Success! 0ms
int isinArray(vector<int> &array, int element)
{
    int n = array.size();
    for (int i = 0; i < n; i++)
    {
        if (array[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> elements;
    vector<int> counts;

    // Get the elements and counts
    for (int i = 0; i < n; i++)
    {
        int ele_idx = isinArray(elements, nums[i]);
        if (ele_idx == -1)
        {
            elements.push_back(nums[i]);
            counts.push_back(0);
        }
        else
        {
            counts[ele_idx]++;
        }
    }

    // Maximum element has to be majority element
    int size = counts.size();
    int max_idx = 0;
    for (int i = 0; i < size; i++)
    {
        if (counts[i] > counts[max_idx])
        {
            max_idx = i;
        }
    }
    return elements[max_idx];
}

int main()
{
    vector<int> input = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(input);
    cout << ans;
    return 0;
}