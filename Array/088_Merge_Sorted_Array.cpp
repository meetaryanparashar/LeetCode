/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++)
        {
            int prev = m+i-1;
            while (prev >=0 &&nums1[prev] > nums2[i] ) 
            // so if first condition of && is false then it will not even check the other condition
            {
                nums1[prev+1] = nums1[prev];
                prev--;
            }
            nums1[prev+1] = nums2[i];
        }
    }

int main(){
    vector<int> input1 = {0};
    vector<int> input2 = {1};

    for (int i = 0; i < 6; i++)
    {
        cout << input1[i] << " ";
    }

    cout << endl;
    
    merge(input1, 0, input2, 1);
    for (int i = 0; i < 6; i++)
    {
        cout << input1[i] << " ";
    }
    
    return 0;
}