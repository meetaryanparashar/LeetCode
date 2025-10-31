/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

#include <iostream>
#include <vector>

using namespace std;


// first appproach

// I got a hint from course to use binary search algorithm. 
int singleNonDuplicate(vector<int> &nums)
{

    int l = 1, r = nums.size() - 2;

    if (nums.size() == 1) // if only 1 element in array
    {
        return nums[0];
    }
    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    if (nums[r] != nums[r + 1])
    {
        return nums[r + 1];
    }

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (mid % 2 == 1)
        {
            if (nums[mid - 1] == nums[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        else
        {
            if (nums[mid - 1] == nums[mid])
            {
                r = mid - 2;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> input = {3, 3, 7, 7, 10, 11, 11};
    cout << singleNonDuplicate(input);
    return 0;
}