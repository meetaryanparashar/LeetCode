/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// First approach
void nextPermutation(vector<int> &nums)
{
    int last = nums.size() - 1;
    while (last > 0 && nums[last] <= nums[last - 1])
    {
        last--;
    }
    if (last == 0)
    {
        sort(nums.begin(), nums.end());  // better to just reverse the array. 
        return;
    }
    // cout << "last is : " << nums[last] << " at : " << last << endl;
    int min_idx = last;
    for (int i = last; i < nums.size(); i++)  
    // better to start searching out pivot from back because backwards array is arranged in decresing order.
    {
        if (nums[i] < nums[min_idx] && nums[i] > nums[last - 1])
        {
            min_idx = i;
        }
    }
    // cout << "min element from " << last << " to  end is : " << nums[min_idx] << " at " << min_idx << endl;

    swap(nums[min_idx], nums[last - 1]);
    sort(nums.begin() + last, nums.end());  // here too better to reverse the array
    return;
}

int main()
{
    vector<int> nums = {3, 2, 1};
    nextPermutation(nums);
    for (int item : nums)
    {
        cout << item << " ";
    }
    return 0;
}
/*
123
132
213
231
312
321*/