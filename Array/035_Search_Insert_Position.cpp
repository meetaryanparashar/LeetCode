/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>

using namespace std;

// Simple binary search approach
int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int m = (l+r)/2;
            if (target < nums[m]){
                r = m-1;
            }
            else if (target > nums[m]){
                l = m+1;
            }
            else{
                return m;
            }
        }
        return l;
    }

int main(){
    vector<int> input = {1,3,5,7};
    int target = 2;
    int ans = searchInsert(input, target);
    cout << ans;
}