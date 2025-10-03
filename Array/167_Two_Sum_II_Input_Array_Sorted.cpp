/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

// Two pointer approach -> O(n)
vector<int> twoSum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    int l = 0, r = n - 1;
    vector<int> ans;

    while (l < r)
    {
        int PS = numbers[l] + numbers[r];
        if (PS > target)
        {
            r--;
        }
        else if (PS < target)
        {
            l++;
        }
        else
        {
            ans.push_back(l + 1);
            ans.push_back(r + 1);
            return ans;
        }
    }
    return ans;
}


int main()
{
    vector<int> input = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(input, target);
    cout << ans[0] << ", "<<ans[1];
    return 0;
}